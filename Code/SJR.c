#include "ProcUtil.h"

void SJRSort(PROCESS Proc[], SIMULATION *Sim);
int SJR(PROCESS Proc[], SIMULATION *Sim);

int SJR(PROCESS Proc[], SIMULATION *Sim)
{
    bool DEBUG = false;
    printf("/*********  Shortest-Job-Remaining Algorithm *********/\n");
    Sim->Schedule = "SJF";
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

        RunCPU(Proc, Sim);
        RunIO(Proc, Sim);

        Sim->Time++;
        if(i == 49)
        {
            ListProcess(Proc, Sim);
            ListSim(Sim);
        }
        //SnapShot(Proc, Sim);

    }

    return 0;
}


void SJRSort(PROCESS Proc[], SIMULATION *Sim)
{
    int i, j, Total = Sim->TotalProc;

    for(i=0; i < Total; i++)
    {
        for(j=0; j < Total-1; j++)
        {

            if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST >= 1))
            {
                if(((Proc[j].CPU_BURST/2) - Proc[j].CPU_Duration) > ((Proc[j+1].CPU_BURST/2) - Proc[j+1].CPU_Duration))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
            else if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST == 0))
            {
                if(((Proc[j].CPU_BURST/2) - Proc[j].CPU_Duration) > (Proc[j+1].CPU_BURST - Proc[j+1].CPU_Duration))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
            else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST >= 1))
            {
                if((Proc[j].CPU_BURST - Proc[j].CPU_Duration) > ((Proc[j+1].CPU_BURST/2) - Proc[j+1].CPU_Duration ))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
            else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST == 0))
            {
                if((Proc[j].CPU_BURST - Proc[j].CPU_Duration) > (Proc[j+1].CPU_BURST - Proc[j+1].CPU_Duration))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
        }
    }
}
