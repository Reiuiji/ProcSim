#include "ProcUtil.h"

void PSSort(PROCESS Proc[], SIMULATION Sim);
int PS(PROCESS Proc[], SIMULATION Sim);


void PSSort(PROCESS Proc[], SIMULATION Sim)
{
    int i,j;

    for(i=0; i < Sim.TotalProc; i++)
    {
        for(j=0; j< Sim.TotalProc-1; j++)
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

int PS(PROCESS Proc[], SIMULATION Sim)
{
    printf("[Debug]: Sorted list\n");
    PSSort(Proc,Sim);
    ListProcess(Proc,Sim);
    printf("[Debug]: Finished Sorting\n");

    int pos = 0;
    int Time = 0;
    while(Sim.TotalProc > 0)
    {


        //void SnapShot(Proc, Sim, "PS");
        //TOTAL--;//one less process
        pos++;//next on the list
    }

    return 0;

}
