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
        Proc[pos].CPU_Duration = 0;
        Proc[pos].DeviceQueue = false;
        Proc[pos].FinishTime = 0;
        Proc[pos].InCPU = false;
        Proc[pos].InIO = false;
        Proc[pos].IO_BURST = ioburst;
        Proc[pos].IO_Duration = 0;
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
    return pos;//return how many Process there are

}

void ListProcess (PROCESS Proc[],SIMULATION *SIM)
{
    int pos;
    bool FullDisplay = true;
    if(FullDisplay == false)
    {
        printf("+---------+---------+---------+---------+\n");
        printf("|PID      |CPU_BURST|IO_Burst |Priority |\n");
        for(pos = 0; pos < SIM->TotalProc; pos++)
        {
            printf("| %-7i | %-7i | %-7i | %-7i |\n", Proc[pos].P_ID, Proc[pos].CPU_BURST, Proc[pos].IO_BURST, Proc[pos].PRIORITY);
        }
        printf("+---------+---------+---------+---------+\n");
    }
    else
    {
        printf("+-----+---------+--------+--------+--------+-----+-----+------+-----+-----+-----+-----+-----+-----+\n");
        printf("| PID |CPU_BURST|IO_Burst|Priority|CPUwthIO|RTime|WTime|TATime|INCPU|IN IO|D Que|R Que|CPU D|IO D |\n");
        for(pos = 0; pos < SIM->TotalProc; pos++)
        {
            printf("| %-3i | %-7i | %-6i | %-6i | %-6i | %-3i | %-3i | %-4i | %-3i | %-3i | %-3i | %-3i | %-3i | %-3i |\n", Proc[pos].P_ID, Proc[pos].CPU_BURST, Proc[pos].IO_BURST, Proc[pos].PRIORITY, Proc[pos].CPU_WITH_IO, Proc[pos].ResponseTime, Proc[pos].WaitTime, Proc[pos].TurnAroundTime, Proc[pos].InCPU, Proc[pos].InIO, Proc[pos].DeviceQueue, Proc[pos].ReadyQueue, Proc[pos].CPU_Duration, Proc[pos].IO_Duration);
        }
        printf("+-----+---------+--------+--------+--------+-----+-----+------+-----+-----+-----+-----+-----+-----+\n");
    }

    return;
}   //ListProcess

void ListSim(SIMULATION *SIM)
{
    printf("+----+----+-----------+--------+----------+------+------+---------+--------+\n");
    printf("|TIME|TInt|CPU_CURRENT|CPU_IDLE|IO_CURRENT|IOProc|RQProc|TotalProc|Schedule|\n");
    printf("| %-2i | %-2i | %-9i | %-6i | %-8i | %-4i | %-4i | %-7i | %-6s |\n",SIM->Time, SIM->TimeInterval, SIM->CPU_Current, SIM->CPU_Idle, SIM->IO_Current, SIM->IOProc, SIM->RQProc, SIM->TotalProc,SIM->Schedule);
    printf("+----+----+-----------+--------+----------+------+------+---------+--------+\n");
}


bool RunCPU(PROCESS Proc[], SIMULATION *SIM)//run based on the Current Ready Que
{
    int pos;
    int Current = -1;//-1 acts as a error if the next for cant find the process

    if(SIM->RQProc > 0 && SIM->CPU_Current == -1)
    {
        SIM->CPU_Current = NextQueue(Proc, SIM);
    }

    if(SIM->CPU_Current == -1)//returns false since there is no more CPU so it is finished
    {
        return false;
    }

    for( pos=0; pos<SIM->TotalProc; pos++)//check each Process to see
    {
        if(Proc[pos].P_ID == SIM->CPU_Current) //search to find which Process it is serving
        {
            Current = pos;
            Proc[Current].InCPU == true;//indicates it is in the CPU
            break; //found the next process to work on
        }
    }

    if(Current == -1)//returns false: cant Find the current Process in the queue
    {
        SIM->CPU_Idle++;//increment the idle time
        return false;
    }

    //increment the WaitTime for Process not in CPU
    for( pos=0; pos<SIM->TotalProc; pos++)
    {
        if(pos!= Current)
        {
            Proc[pos].WaitTime++;
            //Process still have not response
            if(Proc[pos].CPU_Duration == 0)
            {
                Proc[pos].ResponseTime++;
            }
        }
    }

    //output the time line for the snapshot
    if(SIM->Time%SIM->TimeInterval == 0)
    {
        printf("\nt = %i\n",SIM->Time);
        if(SIM->Time == 0)//indicates start of simulation
        {
            int CPUBurstI;
            if(Proc[Current].IO_BURST > 0)
            {
                CPUBurstI = Proc[Current].CPU_WITH_IO;
            }
            else
            {
                CPUBurstI = Proc[Current].CPU_BURST;
            }
            printf("CPU loading job %i : CPU burst (%i) IO burst (%i) \n",Proc[Current].P_ID, CPUBurstI, Proc[Current].IO_BURST);
        }
    }


    // Checks the process data. If there's a program that has finished its CPU burst but needs to finish its IO, it moves it to the device queue.
    if((Proc[Current].CPU_Duration >= Proc[Current].CPU_WITH_IO) && (Proc[Current].IO_BURST > Proc[Current].IO_Duration))
    {
        Proc[Current].DeviceQueue = true; //Added to the Device Queue
        SIM->IOProc++;
        Proc[Current].ReadyQueue = false; //removed from the readyQueue
        SIM->RQProc--;
        Proc[Current].InCPU = false;

        if(SIM->Time%SIM->TimeInterval == 0)
        {
            printf("JOB %i finished CPU burst\n",Proc[Current].P_ID);
        }

        SIM->CPU_Current = NextQueue(Proc, SIM);//grabs the next on the queue

        Current = CPUPIDtoPOS(Proc, SIM);

        if(SIM->Time%SIM->TimeInterval == 0)
        {
            int CPUBurst;
            if(Proc[Current].IO_BURST > 0)
            {
                CPUBurst = Proc[Current].CPU_WITH_IO;
            }
            else
            {
                CPUBurst = Proc[Current].CPU_BURST;
            }
            printf("CPU loading job %i: CPU burst(%i) IO burst(%i)\n",Proc[Current].P_ID, CPUBurst-Proc[Current].CPU_Duration, Proc[Current].IO_BURST-Proc[Current].IO_Duration);
        }

    }

    // Checks the process data. If there's a program that has finished its CPU burst and has finished its IO burst, it gets removed.
    else if((Proc[Current].CPU_Duration == Proc[Current].CPU_BURST) && (Proc[Current].IO_Duration == Proc[Current].IO_BURST ))//(LOADED_CPU_BURST == 0) && (LOADED_IO_BURST == 0))
    {
        Proc[Current].ReadyQueue = false;//out of the ready que
        Proc[Current].FinishTime = SIM->Time; // sets the time when the Process finishes
        Proc[Current].TurnAroundTime = SIM->Time;
        Proc[Current].Complete = true;//yay the process is finished

        if(SIM->Time%SIM->TimeInterval == 0)
        {
            printf("JOB %i DONE\n",Proc[Current].P_ID);
        }

        SIM->CPU_Current = NextQueue(Proc, SIM);//grabs the next on the queue

        Current = CPUPIDtoPOS(Proc, SIM);

        if(SIM->Time%SIM->TimeInterval == 0)
        {
            int CPUBurst;
            if(Proc[Current].IO_BURST > 0)
            {
                CPUBurst = Proc[Current].CPU_WITH_IO;
            }
            else
            {
                CPUBurst = Proc[Current].CPU_BURST;
            }
            printf("CPU loading job %i: CPU burst(%i) IO burst(%i)\n",Proc[Current].P_ID, CPUBurst-Proc[Current].CPU_Duration, Proc[Current].IO_BURST-Proc[Current].IO_Duration);
        }

    }
    else
    {
        if((SIM->Time%SIM->TimeInterval == 0) && (SIM->Time != 0))
        {
            int CPUBurst;
            if(Proc[Current].IO_BURST > 0)
            {
                CPUBurst = Proc[Current].CPU_WITH_IO;
            }
            else
            {
                CPUBurst = Proc[Current].CPU_BURST;
            }

            printf("Servicing %s job %i: CPU burst(%i) IO burst(%i)\n",SIM->Schedule, Proc[Current].P_ID, CPUBurst - Proc[Current].CPU_Duration, Proc[Current].IO_BURST - Proc[Current].IO_Duration );
        }
    }

    if(SIM->Time%SIM->TimeInterval == 0)
    {
        DisplayReadyQueue(Proc, SIM);
    }

    // Otherwise it should be in a situation where it just needs to run normally.

    //Does all what it needs for the Current Process
    Proc[Current].CPU_Duration++;

    return true;
}

bool RunIO(PROCESS Proc[], SIMULATION *SIM)//run based on the Current IO
{
    int pos;
    int Current = -1;//-1 acts as a error if the next for cant find the process


    if(SIM->Time == 0)//indicates start of simulation
    {
        DisplayDeviceQueue(Proc, SIM);
    }

    if(SIM->IOProc > 0 && SIM->IO_Current == -1)
    {
        SIM->IO_Current = NextIO(Proc, SIM);
    }

    if(SIM->IO_Current == -1)//returns false since there is no more IO so it is finished
    {
        return false;
    }

    for( pos=0; pos<SIM->TotalProc; pos++)//check each Process to see
    {
        if(Proc[pos].P_ID == SIM->IO_Current) //search to find which Process it is serving
        {
            Current = pos;
            Proc[Current].InIO == true;//indicates it is in the IO
            break; //found the next process to work on
        }
    }

    if(Current == -1)//returns false: cant Find the current Process in the queue
    {
        return false;
    }


    //Does all what it needs for the Current Process
    Proc[Current].IO_Duration++;

    // Checks the process data. If there's a program that has finished its IO burst but needs to finish its IO, it moves it to the device queue.
    if(Proc[Current].IO_Duration >= Proc[Current].IO_BURST)
    {
        Proc[Current].ReadyQueue = true; //Added to the Ready Queue
        SIM->RQProc++;
        Proc[Current].DeviceQueue = false; //removed from the Device Queue
        SIM->IOProc++;
        Proc[Current].InIO = false;

        if(SIM->Time%SIM->TimeInterval == 0)
        {
            printf("JOB %i finished IO burst\n",Proc[Current].P_ID);
        }

        SIM->CPU_Current = NextIO(Proc, SIM);//grabs the next on the queue

    }

    if(SIM->Time%SIM->TimeInterval == 0)
    {
        DisplayDeviceQueue(Proc, SIM);
    }


    return true;
}

int NextQueue(PROCESS Proc[], SIMULATION *SIM)
{
    int i;
    int Current = CPUPIDtoPOS(Proc, SIM);

    for(i=1/*next process*/; i<SIM->TotalProc-1; i++) //checks the rest of the process
    {
        if(Proc[(i+Current)%SIM->TotalProc].ReadyQueue == true) //checks the next proc on the list to see if it needs to be in the Que
        {
            return Proc[(i+Current)%SIM->TotalProc].P_ID; //return the PID
        }
    }

    return -1;//means it checked and there is no queues left to run
}

int NextIO(PROCESS Proc[], SIMULATION *SIM)
{
    int i;
    int Current = IOPIDtoPOS(Proc, SIM);

    for(i=1/*next process*/; i<SIM->TotalProc-1; i++) //checks the rest of the process
    {
        if(Proc[(i+Current)%SIM->TotalProc].DeviceQueue == true) //checks the next proc on the list to see if it needs to be in the Que
        {
            return Proc[(i+Current)%SIM->TotalProc].P_ID;
        }
    }

    return -1;//means it checked and there is no queues left to run
}

int CPUPIDtoPOS(PROCESS Proc[],SIMULATION *SIM)//this will convert PID to the array position
{
    int pos;
    for( pos=0; pos<SIM->TotalProc; pos++)//check each Process to see
    {
        if(Proc[pos].P_ID == SIM->CPU_Current) //search to find which Process it is serving
        {
            return pos;
        }
    }
    return -1; //error cant find
}

int IOPIDtoPOS(PROCESS Proc[],SIMULATION *SIM)//this will convert PID to the array position
{
    int pos;
    for( pos=0; pos<SIM->TotalProc; pos++)//check each Process to see
    {
        if(Proc[pos].P_ID == SIM->IO_Current) //search to find which Process it is serving
        {
            return pos;
        }
    }
    return -1; //error cant find
}

void DisplayReadyQueue(PROCESS Proc[],SIMULATION *SIM)
{
    int pos;
    bool FirstOccur = true;

    printf("current state of ready queue: ");

    for(pos = 0; pos < SIM->TotalProc; pos++)
    {
        if(Proc[pos].ReadyQueue == true)
        {
            if(FirstOccur == false)
            {
                printf("-");
            }
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

void DisplayDeviceQueue(PROCESS Proc[],SIMULATION *SIM)
{
    int pos;
    bool FirstOccur = true;

    printf("current state of device queue: ");

    for(pos = 0; pos < SIM->TotalProc; pos++)
    {
        if(Proc[pos].DeviceQueue == true)
        {
            if(FirstOccur == false)
            {
                printf("-");
            }
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

void SnapShot(PROCESS Proc[], SIMULATION *SIM)//, char **)
{
    if(SIM->Time%SIM->TimeInterval == 0)
    {
        int Cur = CPUPIDtoPOS(Proc, SIM);
        if(Cur == -1)//cant find
        {
            SIM->CPU_Current = NextQueue(Proc, SIM);
            Cur = CPUPIDtoPOS(Proc, SIM);
        }
        printf("t = %i\n",SIM->Time);
        if(SIM->Time == 0)//indicates start of simulation
        {
            printf("CPU loading job %i : CPU burst (%i) IO burst (%i) \n",Proc[Cur].P_ID, Proc[Cur].CPU_WITH_IO, Proc[Cur].IO_BURST);
        }
        else
        {
            //outputs if the Process Just finishes
            if((Proc[Cur].CPU_Duration == Proc[Cur].CPU_BURST) && (Proc[Cur].InCPU == true) && (Proc[Cur].InIO == false)) //signifies that it just finished the CPU Burst
            {
                printf("JOB %i DONE\n", Proc[Cur].P_ID);
                int NextQue = NextQueue(Proc,SIM);
                printf("CPU loading Job %i: CPU burst(%i) IO burst(%i)\n",Proc[NextQue].P_ID, Proc[NextQue].CPU_WITH_IO, Proc[NextQue].IO_BURST);
            }
            else
            {
                if((Proc[Cur].CPU_Duration == Proc[Cur].CPU_BURST) && (Proc[Cur].InCPU == true) && (Proc[Cur].InIO == true))//signifies that it just finished the CPU but need IO Burst time
                {
                    printf("JOB %i Finished  CPU burst\n", Proc[Cur].P_ID);
                    int NextQue = NextQueue(Proc,SIM);
                    printf("CPU loading Job %i: CPU burst(%i) IO burst(%i)\n",Proc[NextQue].P_ID, Proc[NextQue].CPU_WITH_IO, Proc[NextQue].IO_BURST);
                }
                else
                {
                    printf("Servicing %s job %i: CPU burst (%i) IO burst (%i) \n",SIM->Schedule, Proc[Cur].P_ID, Proc[Cur].CPU_WITH_IO, Proc[Cur].IO_BURST);

                }

            }
        }

        DisplayReadyQueue(Proc, SIM);
        DisplayDeviceQueue(Proc, SIM);

    }
}

int Array_test(FILE* INPUT,SIMULATION *SIM)
{
    printf("+Array test+\n");
    PROCESS  test[SIM->TotalProc];
    InputFromFile(test,INPUT);
    ListProcess(test,SIM);
    printf("-Array test-\n");
    return 0;
}

