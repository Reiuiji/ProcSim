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
        //Set all the variables For the Process
        Proc[pos].Complete = false;
        Proc[pos].CPU_BURST = cpuburst;
        Proc[pos].DeviceQueue = false;
        Proc[pos].FinishTime = 0;
        Proc[pos].InCPU = false;
        Proc[pos].InIO = false;
        Proc[pos].IO_BURST = ioburst;
        Proc[pos].P_ID = pid;
        Proc[pos].PRIORITY = priority;
        Proc[pos].ReadyQueue = true;
        Proc[pos].ResponseTime = 0;
        Proc[pos].TurnAroundTime = 0;
        Proc[pos].WaitTime = 0;

        //set the IO hald burst
        if(ioburst != 0)
        {
            Proc[pos].CPU_WITH_IO = cpuburst/2;
        }
        else
        {
            Proc[pos].CPU_WITH_IO = 0;
        }
        pos++;

    }
    return 0;

}

void ListProcess (PROCESS Proc[],SIMULATION SIM)
{
    int pos;
    bool FullDisplay = true;
    if(FullDisplay == false)
    {
    printf("+---------+---------+---------+---------+\n");
    printf("|PID      |CPU_BURST|IO_Burst |Priority |\n");
    for(pos = 0; pos < SIM.TotalProc; pos++)
    {
        printf("| %-7i | %-7i | %-7i | %-7i |\n", Proc[pos].P_ID, Proc[pos].CPU_BURST, Proc[pos].IO_BURST, Proc[pos].PRIORITY);
    }
    printf("+---------+---------+---------+---------+\n");
    }
    else
     {
     printf("+-----+---------+--------+--------+-----+-----+------+-----+-----+-----+-----+\n");
    printf("| PID |CPU_BURST|IO_Burst|Priority|RTime|WTime|TATime|INCPU|IN IO|D Que|R Que|\n");
    for(pos = 0; pos < SIM.TotalProc; pos++)
    {
        printf("| %-3i | %-7i | %-6i | %-6i | %-3i | %-3i | %-4i | %-3i | %-3i | %-3i | %-3i |\n", Proc[pos].P_ID, Proc[pos].CPU_BURST, Proc[pos].IO_BURST, Proc[pos].PRIORITY, Proc[pos].ResponseTime, Proc[pos].WaitTime, Proc[pos].TurnAroundTime, Proc[pos].InCPU, Proc[pos].InIO, Proc[pos].DeviceQueue, Proc[pos].ReadyQueue);
    }
     printf("+-----+---------+--------+--------+-----+-----+------+-----+-----+-----+-----+\n");
    }

	return;
}   //ListProcess

void DisplayReadyQueue(PROCESS Proc[],SIMULATION SIM)
{
    int pos;
    bool FirstOccur = true;

    printf("current state of ready queue: ");

    for(pos = 0; pos < SIM.TotalProc; pos++)
    {
        if(FirstOccur == false)
        {
            printf("-");
        }
        if(Proc[pos].ReadyQueue == true)
        {
            printf("%i",Proc[pos].P_ID);
            if(FirstOccur == true)
            {
                FirstOccur = false;
            }
        }
    }
    if(FirstOccur == true)
    {
        printf("EMPTY");
    }
    printf("\n");
}

void DisplayDeviceQueue(PROCESS Proc[],SIMULATION SIM)
{
    int pos;
    bool FirstOccur = true;

    printf("current state of device queue: ");

    for(pos = 0; pos < SIM.TotalProc; pos++)
    {
        if(FirstOccur == false)
        {
            printf("-");
        }
        if(Proc[pos].DeviceQueue == true)
        {
            printf("%i",Proc[pos].P_ID);
            if(FirstOccur == true)
            {
                FirstOccur = false;
            }
        }
    }
    if(FirstOccur == true)
    {
        printf("EMPTY");
    }
    printf("\n");
}

void SnapShot(PROCESS Proc[], SIMULATION SIM)//, char **)
{
    int i;
    if(SIM.Time%SIM.TimeInterval == 0)
    {
        printf("t = %i\n",SIM.Time);
        if(SIM.Time == 0)//indicates start of simulation
        {
            printf("CPU loading job %i : CPU burst (%i) IO burst (%i) \n",Proc[0].P_ID, Proc[0].CPU_WITH_IO, Proc[0].IO_BURST);
        }

DisplayReadyQueue(Proc, SIM);
DisplayDeviceQueue(Proc, SIM);

    }
}

int Array_test(FILE* INPUT,SIMULATION SIM)
{
    printf("+Array test+\n");
    PROCESS  test[SIM.TotalProc];
    InputFromFile(test,INPUT);
    ListProcess(test,SIM);
    printf("-Array test-\n");
    return 0;
}

