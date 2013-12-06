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
    if(DEBUG == true)
    {
        ListProcess(Proc, Sim);
        ListSim(Sim);
    }


    int i;
    for(i = 0; i<82; i++)
    {
        CheckCPU(Proc, Sim);
        CheckIO(Proc, Sim);

        SJRSort(Proc, Sim);

        /* The preemptive check was supposed to check whether or not the process currently loaded in the CPU
        had a CPU burst greater than something waiting in the queue, but it doesn't seem to be working. */

//        PreemptiveCheck(Proc, Sim);

        /* This sort occurs after the preemptive check because it sorts after something is added. */

//        SJRSort(Proc, Sim);

        RunCPU(Proc, Sim);
        RunIO(Proc, Sim);

        Sim->Time++;

        if(i == 47 || i == 48 || i == 49 || i == 50)
        {
            ListProcess(Proc, Sim);
            ListSim(Sim);
            printf("The leftover CPU of Process 7 is: %d\n The leftover CPU of Process 2 is: %d",
                   (Proc[7].CPU_BURST - Proc[7].CPU_Duration),
                                      (Proc[8].CPU_BURST - Proc[8].CPU_Duration));
        }
        //SnapShot(Proc, Sim);

    }

    return 0;
}

// Okay I think I figured out the problem.
// The problem is that once the file is loaded into CPU it cannot be compared.
// There needs to be a loop that compares everything to the CPU.
// If something is lesser, it swaps it with the CPU.

void SJRSort(PROCESS Proc[], SIMULATION *Sim)
{
    int i, j, Total = Sim->TotalProc;

    for(i=0; i < Total; i++)
    {
        for(j=0; j < Total-1; j++)
        {

            if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST >= 1))
            {
                if(((Proc[j].CPU_BURST/2) - Proc[j].CPU_Duration) > ((Proc[(j+1)].CPU_BURST/2) - Proc[(j+1)].CPU_Duration))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }

            else if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST == 0))
            {
                if(((Proc[j].CPU_BURST/2) - Proc[j].CPU_Duration) > (Proc[(j+1)].CPU_BURST - Proc[(j+1)].CPU_Duration))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }

            else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST >= 1))
            {
                if((Proc[j].CPU_BURST - Proc[j].CPU_Duration) > ((Proc[(j+1)].CPU_BURST/2) - Proc[(j+1)].CPU_Duration))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }

            else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST == 0))
            {
                if(((Proc[j].CPU_BURST) - Proc[j].CPU_Duration) > ((Proc[(j+1)].CPU_BURST) - Proc[(j+1)].CPU_Duration))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
        }
    }
}
