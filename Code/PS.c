#include "ProcUtil.h"

void PSSort(PROCESS Proc[], SIMULATION *Sim);
int PS(PROCESS Proc[], SIMULATION *Sim);

int PS(PROCESS Proc[], SIMULATION *Sim)
{
    printf("/***********  Priority-Scheduling Algorithm ***********/\n");

    Sim->Schedule = "PS";

    PSSort(Proc, Sim);

    //setup ready/IO current
    Sim->CPU_Current = Proc[0].P_ID;
    Sim->IO_Current = -1;

    CheckCPU(Proc, Sim);
    CheckIO(Proc, Sim);

    while(IsProcComplete(Proc, Sim))
    {
        PSSort(Proc, Sim);

        RunCPU(Proc, Sim);
        RunIO(Proc, Sim);
        Sim->Time++;

        CheckCPU(Proc, Sim);
        CheckIO(Proc, Sim);
    }
    Proc[CPUPIDtoPOS(Proc, Sim)].TurnAroundTime = Sim->Time;
    Sim->CPU_Current = -1;

    FinalReport(Proc, Sim);

    return 0;

}

void PSSort(PROCESS Proc[], SIMULATION *Sim)
{
    int i,j;

    for(i=0; i < Sim->TotalProc; i++)
    {
        for(j=0; j< Sim->TotalProc-1; j++)
        {
            if(Proc[j].PRIORITY > Proc[j+1].PRIORITY)
            {
                PROCESS tmp = Proc[j+1];
                Proc[j+1] = Proc[j];
                Proc[j] = tmp;
            }
        }
    }
}
