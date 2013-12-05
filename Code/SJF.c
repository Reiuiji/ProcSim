#include "ProcUtil.h"

void SJFSort(PROCESS Proc[], SIMULATION *Sim);
int SJF(PROCESS Proc[], SIMULATION *Sim);

int SJF(PROCESS Proc[], SIMULATION *Sim)
{
    bool DEBUG = false;
    printf("/***********  Shortest-Job-First Algorithm ***********/\n");
    Sim->Schedule = "SJF";
    SJFSort(Proc, Sim);
//    printf("[+DEBUG+]\n");
//    ListProcess(Proc, Sim);
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
    SnapShot(Proc, Sim);


    int i;
    for(i = 0; i<20; i++)
    {
        RunCPU(Proc, Sim);
        RunIO(Proc, Sim);
        Sim->Time++;
        if(DEBUG == true)
        {
            ListProcess(Proc, Sim);
            ListSim(Sim);
        }
        SnapShot(Proc, Sim);
        SJFSort(Proc, Sim);
    }


}


void SJFSort(PROCESS Proc[], SIMULATION *Sim)
{
    int i, j, Total = Sim->TotalProc;

    for(i=0; i < Total; i++)
    {
        for(j=0; j < Total-1; j++)
        {

            if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST >= 1))
            {
                if((Proc[j].CPU_BURST/2) > (Proc[j+1].CPU_BURST/2))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
            else if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST == 0))
            {
                if((Proc[j].CPU_BURST/2) > Proc[j+1].CPU_BURST)
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
            else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST >= 1))
            {
                if(Proc[j].CPU_BURST > (Proc[j+1].CPU_BURST/2))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
            else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST == 0))
            {
                if(Proc[j].CPU_BURST > Proc[j+1].CPU_BURST)
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
        }
    }
}
