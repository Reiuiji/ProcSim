#include "ProcUtil.h"
#include <stdio.h>
#include <stdbool.h>





/* ===========================

            Functions

  ============================= */


//Input to the array
int InputFromFile(PROCESS Proc[], FILE *InputFile)
{
    int pid,cpuburst, ioburst, priority;

    //PROCESS* Process[10];//hardlock 10 process, need to fix
    int pos = 0;
    while( fscanf(InputFile, "%i %i %i %i", &pid, &cpuburst, &ioburst, &priority) == 4)
    {
        Proc[pos].P_ID = pid;
        Proc[pos].CPU_BURST = cpuburst;
        Proc[pos].IO_BURST = ioburst;
        Proc[pos].PRIORITY = priority;
        pos++;

    }
    return 0;

}

void ListProcess (PROCESS Proc[],int Total)
{
    int pos;
    printf("+---------+---------+---------+---------+\n");
    printf("|PID      |CPU_BURST|IO_Burst |Priority |\n");
    for(pos = 0; pos < Total; pos++)
    {
        printf("| %-7i | %-7i | %-7i | %-7i |\n", Proc[pos].P_ID, Proc[pos].CPU_BURST, Proc[pos].IO_BURST, Proc[pos].PRIORITY);
    }
    printf("+---------+---------+---------+---------+\n");
	return;
}   //ListProcess

void SnapShot(PROCESS Proc[], int CurrentTime, int TimeInverval)
{

}
int Array_test(FILE* INPUT,int Total)
{
printf("+Array test+\n");
PROCESS  test[Total];
InputFromFile(test,INPUT);
ListProcess(test,Total);
printf("-Array test-\n");
return 0;
}

