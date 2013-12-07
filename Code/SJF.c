#include "ProcUtil.h"

void SJFSort(PROCESS Proc[], SIMULATION *Sim);
int SJF(PROCESS Proc[], SIMULATION *Sim);
//void IO_SJF(PROCESS Proc[], SIMULATION *Sim);

int SJF(PROCESS Proc[], SIMULATION *Sim)
{
    bool DEBUG = false;
    printf("/***********  Shortest-Job-First Algorithm ***********/\n");
    Sim->Schedule = "SJF";
    SJFSort(Proc, Sim);
//    printf("[+DEBUG+]\n");
    //ListProcess(Proc, Sim);
//    printf("[-DEBUG-]\n");

    //setup ready current and IO current
    int current = Proc[0].P_ID;
    Sim->CPU_Current = current;//set at the first Process in the ready Que
    Sim->IO_Current = -1;//there is none
    if(DEBUG == true)
    {
        ListProcess(Proc, Sim);
        ListSim(Sim);
    }
    //SnapShot(Proc, Sim);
//

    CheckCPU(Proc, Sim);
    CheckIO(Proc, Sim);

    int i;
    while(IsProcComplete(Proc, Sim))
    {


        SJFSort(Proc, Sim);

        //IO_SJF(Proc, Sim);
        RunCPU(Proc, Sim);
        RunIO(Proc, Sim);
        Sim->Time++;
        if(DEBUG == true)
        {
            ListProcess(Proc, Sim);
            ListSim(Sim);
        }

        CheckCPU(Proc, Sim);
        CheckIO(Proc, Sim);
        //SnapShot(Proc, Sim);

    }
    //Set the last proc Response time
    current = CPUPIDtoPOS(Proc, Sim);
    Proc[current].TurnAroundTime = Sim->Time;
    Sim->CPU_Current = -1; //NO More process it needs to work on

    //ListProcess(Proc, Sim);
    //ListSim(Sim);

    FinalReport(Proc, Sim);

    return 0;
}


/* This is the sorting algorithm for shortest job first */
void SJFSort(PROCESS Proc[], SIMULATION *Sim)
{
    int i, j, Total = Sim->TotalProc;

    for(i=0; i < Total; i++)
    {
        for(j=0; j < Total-1; j++)
        {
            /* The first thing that it does is check to see whether or not the processes have IO bursts left.
            The IO_Burst is the entire IO burst cycle, and the duration is how long it has run so far. */

            // If both Process j and process j+1 have unfinished IO bursts
            if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST >= 1))
            {
                /* They will use half-IO bursts to determine reordering. This is accomplished by using CPU_WITH_IO instead
                of CPU_BURST, as it contains what the half of the entire CPU burst cycle will be. */
                if((Proc[j].CPU_WITH_IO) > (Proc[j+1].CPU_WITH_IO))
                {
                    // if true, it reorders them in the queue
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }

            // If process j has an unfinished IO burst and process j+1 has no unfinished IO burst
            else if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST == 0))
            {
                 // The first process uses a half CPU burst for checking and the next will use a full cpu burst.
                if((Proc[j].CPU_WITH_IO) > Proc[j+1].CPU_BURST)
                {
                    // if true, it reorders them in the queue
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }

            // If process j has no IO burst and process j+1 has an unfinished IO burst
            else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST >= 1))
            {
                 // The first process uses a full CPU burst for checking and the next will use a half cpu burst.
                if(Proc[j].CPU_BURST > (Proc[j+1].CPU_WITH_IO))
                {
                    // if true, it reorders them in the queue
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }

            // If both Process j and process j+1 have no IO bursts
            else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST == 0))
            {
                 // The first process uses a full CPU burst for checking and the next will use a full cpu burst.
                if(Proc[j].CPU_BURST > Proc[j+1].CPU_BURST)
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
