#include "ProcUtil.h"

void PSSort(PROCESS Proc[],int Total);
int PS(PROCESS Proc[], int TOTAL, int SnapShotTime);


void PSSort(PROCESS Proc[],int Total)
{
    int i,j;

    for(i=0; i < Total; i++)
    {
        for(j=0; j< Total-1; j++)
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

int PS(PROCESS Proc[], int TOTAL, int SnapShotTime)
{
    printf("[Debug]: Sorted list\n");
    PSSort(Proc,TOTAL);
    ListProcess(Proc,TOTAL);
    printf("[Debug]: Finished Sorting\n");
    return 0;

}
