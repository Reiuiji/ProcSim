#include "ProcUtil.h"

void SJRSort(PROCESS Proc[], SIMULATION *Sim);
int SJR(PROCESS Proc[], SIMULATION *Sim);

int SJR(PROCESS Proc[], SIMULATION *Sim)
{
    bool DEBUG = false;
    printf("/*********  Shortest-Job-Remaining Algorithm *********/\n");
    Sim->Schedule = "SJR";
    SJRSort(Proc, Sim);

    //setup ready current and IO current
    int current = Proc[0].P_ID;
    Sim->CPU_Current = current; //set at the first Process in the ready Que
    Sim->IO_Current = -1; //there is none
    Sim->PCheck = true; //enable preemtive check
    if(DEBUG == true)
    {
        ListProcess(Proc, Sim);
        ListSim(Sim);
    }

    int i;

    CheckCPU(Proc, Sim); // Checks the CPU to move / remove any finished CPU processes
    CheckIO(Proc, Sim);  // Checks the IO to move / remove any finished IO processes

    while(IsProcComplete(Proc, Sim)) // While loop that keeps going until everything is finished
    {
        //PCheckSort(Proc, Sim);
        SJRSort(Proc, Sim);
if(Sim->Time == 50)
{
    ListProcess(Proc, Sim);
    ListSim(Sim);
}
        RunCPU(Proc, Sim); // Simulates a running of the CPU
        RunIO(Proc, Sim); // Simulates a running of the IO

        Sim->Time++; // Updates the timer

        SJRSort(Proc, Sim); // Uses the SJR Sort function to sort by Shortest Job Remaining
        // PreemptiveCheck(Proc, Sim);
        /* The preemptive check is supposed to work but just goes haywire. */
        /* Preemptive check is located under the ProcUtil.c file. */

        CheckCPU(Proc, Sim); // Checks the CPU to move / remove any finished CPU processes
        CheckIO(Proc, Sim);  // Checks the IO to move / remove any finished IO processes


        if(DEBUG == true)
        {
            ListProcess(Proc, Sim);
            ListSim(Sim);
        }

        // PreemptiveCheck(Proc,Sim);
        //SnapShot(Proc, Sim);


        /* The preemptive check was supposed to check whether or not the process currently loaded in the CPU
        had a CPU burst greater than something waiting in the queue, but it doesn't seem to be working. */

        // PreemptiveCheck(Proc, Sim);

        /* This sort occurs after the preemptive check because it sorts after something is added. */
    }



    //Set the last proc Response time
    current = CPUPIDtoPOS(Proc, Sim);
    Proc[current].TurnAroundTime = Sim->Time;
    Sim->CPU_Current = -1; //NO More process it needs to work on

    ListProcess(Proc, Sim);
    ListSim(Sim);

    FinalReport(Proc, Sim);

    return 0;
}

// Okay I think I figured out the problem.
// The problem is that once the file is loaded into CPU it cannot be compared.
// There needs to be a loop that compares everything to the CPU.
// If something is lesser, it swaps it with the CPU.


/* This is the sorting algorithm for SJR. It is supposed to be preemptive. */
void SJRSort(PROCESS Proc[], SIMULATION *Sim)
{
    int i, j, Total = Sim->TotalProc;

    for(i=0; i < Total; i++)
    {
        for(j=0; j < Total-1; j++)
        {
            /* The first thing that it does is check to see whether or not the processes have IO bursts left.
            The IO_Burst is the entire IO burst cycle, and the duration is how long it has run so far. */

            // If both Process j and process j+1 have unfinished IO bursts
            if ((Proc[j].IO_BURST-Proc[j].IO_Duration >= 1) && (Proc[j+1].IO_BURST-Proc[j+1].IO_Duration >= 1))
            {
                /* They will use half-IO bursts to determine reordering. This is accomplished by using CPU_WITH_IO instead
                of CPU_BURST, as it contains what the half of the entire CPU burst cycle will be. */
                if(((Proc[j].CPU_WITH_IO) - Proc[j].CPU_Duration) > ((Proc[(j+1)].CPU_WITH_IO) - Proc[(j+1)].CPU_Duration))
                {
                    // if true, it reorders them in the queue
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }

            // If the first process has an IO burst left and the next does not
            else if((Proc[j].IO_BURST-Proc[j].IO_Duration >= 1) && (Proc[j+1].IO_BURST-Proc[j+1].IO_Duration == 0))
            {
                // The first process uses a half CPU burst for checking and the next will use a full cpu burst.
                if(((Proc[j].CPU_WITH_IO) - Proc[j].CPU_Duration) > (Proc[(j+1)].CPU_BURST - Proc[(j+1)].CPU_Duration))
                {
                    // if true, it reorders them in the queue
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }

            // If the first process has no IO burst left and the next does
            else if((Proc[j].IO_BURST-Proc[j].IO_Duration == 0) && (Proc[j+1].IO_BURST-Proc[j+1].IO_Duration >= 1))
            {
                // The first process uses its full cpu burst for checking and the next will use a half burst
                if((Proc[j].CPU_BURST - Proc[j].CPU_Duration) > ((Proc[(j+1)].CPU_WITH_IO) - Proc[(j+1)].CPU_Duration))
                {
                    // if true, it reorders them in the queue
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }

            // If neither of the two processes have IO bursts
            else if((Proc[j].IO_BURST-Proc[j].IO_Duration == 0) && (Proc[j+1].IO_BURST-Proc[j+1].IO_Duration == 0))
            {
                // Both will use their full cpu bursts for checking.
                if(((Proc[j].CPU_BURST) - Proc[j].CPU_Duration) > ((Proc[(j+1)].CPU_BURST) - Proc[(j+1)].CPU_Duration))
                {
                    // if true, it reorders them in the queue
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
        }
    }
}
