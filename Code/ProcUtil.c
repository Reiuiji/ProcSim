#include "ProcUtil.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>





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

bool CheckCPU(PROCESS Proc[], SIMULATION *SIM)
{
    int pos;
    for(pos = 0 ; pos < SIM->TotalProc; pos++)
    {
        if((Proc[pos].CPU_BURST == Proc[pos].CPU_Duration) && (Proc[pos].Complete == false))//finished all the CPU time required
        {
            if(Proc[pos].IO_BURST == Proc[pos].IO_Duration)
            {
                Proc[pos].Complete = true;
                Proc[pos].ReadyQueue = false;
                Proc[pos].DeviceQueue = false;
            }
            else
            {
                Proc[pos].ReadyQueue = false;
                Proc[pos].DeviceQueue = true;
            }
        }
        else if((Proc[pos].CPU_BURST == Proc[pos].CPU_WITH_IO) && (Proc[pos].IO_BURST > 0))
        {
            Proc[pos].ReadyQueue = false;
            Proc[pos].DeviceQueue = true;
        }
    }
}

bool CheckIO(PROCESS Proc[], SIMULATION *SIM)
{
    int pos;
    for(pos = 0 ; pos < SIM->TotalProc; pos++)
    {
        if((Proc[pos].IO_BURST == Proc[pos].IO_Duration) && (Proc[pos].DeviceQueue == true))//finished all the IO time required
        {
            if(Proc[pos].CPU_BURST == Proc[pos].CPU_Duration)
            {
                Proc[pos].Complete = true;
                Proc[pos].ReadyQueue = false;
                Proc[pos].DeviceQueue = false;
            }
            else
            {
                Proc[pos].ReadyQueue = true;
                Proc[pos].DeviceQueue = false;
                if(SIM->IOJFinished == -1)
                {
                    SIM->IOJFinished = Proc[pos].P_ID;
                }
            }
        }
    }
}

void PreemptiveCheck(PROCESS Proc[], SIMULATION *SIM)
{
    int cpu, next_queue, k;

    // This grabs the value for the process currently in the CPU.
    for(k=0; k<SIM->TotalProc; k++)
    {
        cpu = -1;
        if(Proc[k].P_ID == (SIM->CPU_Current))
            cpu = k;
        if(cpu != -1)
            break;
    }

    // This checks to see what is currently the first thing for grabs in the queue.
    for(k=0; k<SIM->TotalProc; k++)
    {
        next_queue = -1;
        if((Proc[k].ReadyQueue == true) && (Proc[k].DeviceQueue == false) && (k != cpu))
            next_queue = k;
        if(next_queue != -1)
            break;
    }
    printf("\nOne of the checks is happening...");
    printf("%d %d\n", Proc[cpu].P_ID, Proc[next_queue].P_ID);
    printf("Left for Proc cpu: %d\n", (Proc[cpu].CPU_BURST - Proc[cpu].CPU_Duration));
    printf("Left for next proc: %d\n", (Proc[next_queue].CPU_BURST - Proc[next_queue].CPU_Duration));


    // If both exist we are able to check the two together.
    if((cpu >= 0) && (next_queue >= -0) && ((Proc[cpu].CPU_BURST - Proc[cpu].CPU_Duration) >= 1) && ((Proc[next_queue].CPU_BURST - Proc[next_queue].CPU_Duration) >= 1))
    {
        printf("\n\nOne of the checks is happening...\n\n");
        printf("Process CPU is: %d\nIts Burst is: %d, Its Completion is: %d\n, Its IO is: %d\n", Proc[cpu].P_ID, Proc[cpu].CPU_BURST, Proc[cpu].CPU_Duration, Proc[cpu].IO_BURST-Proc[cpu].IO_Duration);
        printf("Process next is: %d\nIts Burst is: %d, Its Completion is: %d\n, Its IO is: %d\n", Proc[next_queue].P_ID, Proc[next_queue].CPU_BURST, Proc[next_queue].CPU_Duration, Proc[next_queue].IO_BURST-Proc[next_queue].IO_Duration);

        // If the job in the CPU has an IO burst time and the next process has an IO burst time
        if ((Proc[cpu].IO_BURST-Proc[cpu].IO_Duration >= 1) && (Proc[next_queue].IO_BURST >= 1))
        {
            printf("Check");
            // It checks to see which one has the shorter IO time using their half bursts.
            if(((Proc[cpu].CPU_WITH_IO) - Proc[cpu].CPU_Duration) > ((Proc[next_queue].CPU_WITH_IO) - Proc[cpu].CPU_Duration-Proc[next_queue].IO_Duration))
            {
                // It swaps them and makes my life easier
                PROCESS tmp = Proc[cpu];
                Proc[cpu] = Proc[next_queue];
                Proc[next_queue] = tmp;
                SIM->CPU_Current = next_queue;
                printf("\nyes\n");
            }
        }

        // If only the job in the CPU has an IO burst time
        else if ((Proc[cpu].IO_BURST-Proc[cpu].IO_Duration >= 1) && (Proc[next_queue].IO_BURST-Proc[next_queue].IO_Duration == 0))
        {
            // It checks to see which one has the shorter IO time using their half bursts.
            if(((Proc[cpu].CPU_WITH_IO) - Proc[cpu].CPU_Duration) > ((Proc[next_queue].CPU_BURST) - Proc[cpu].CPU_Duration))
            {
                // I really hope that they actually swap
                PROCESS tmp = Proc[cpu];
                Proc[cpu] = Proc[next_queue];
                Proc[next_queue] = tmp;
                SIM->CPU_Current = next_queue;
                printf("\nyes\n");
            }
        }

        // If only the the next process has an IO burst time
        else if ((Proc[cpu].IO_BURST-Proc[cpu].IO_Duration == 0) && (Proc[next_queue].IO_BURST-Proc[next_queue].IO_Duration >= 1))
        {
            // It checks to see which one has the shorter IO time using their half bursts.
            if(((Proc[cpu].CPU_BURST) - Proc[cpu].CPU_Duration) > ((Proc[next_queue].CPU_WITH_IO) - Proc[cpu].CPU_Duration))
            {
                // Seriously, I've written this section maybe 10 times
                PROCESS tmp = Proc[cpu];
                Proc[cpu] = Proc[next_queue];
                Proc[next_queue] = tmp;
                SIM->CPU_Current = next_queue;
                printf("\nyes\n");
            }
        }

        // If there are no IO burst times
        else if ((Proc[cpu].IO_BURST-Proc[cpu].IO_Duration == 0) && (Proc[next_queue].IO_BURST-Proc[next_queue].IO_Duration == 0))
        {
            // It checks to see which one has the shorter IO time using their half bursts.
            if(((Proc[cpu].CPU_BURST) - Proc[cpu].CPU_Duration) > ((Proc[next_queue].CPU_BURST) - Proc[cpu].CPU_Duration))
            {
                // If this code breaks again I am going to flip a table
                PROCESS tmp = Proc[cpu];
                Proc[cpu] = Proc[next_queue];
                Proc[next_queue] = tmp;
                SIM->CPU_Current = next_queue;
                printf("\nyes\n");
            }
        }
    }
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
        if((pos!= Current) && (Proc[pos].Complete == false))
        {
            Proc[pos].WaitTime++;
        }
    }



    //output the time line for the snapshot
    if(SIM->Time%SIM->TimeInterval == 0)
    {
        printf("\nt = %i\n",SIM->Time);
        if(SIM->Time == 0)//indicates start of simulation
        {
            int CPUBurstI;
            if((Proc[Current].IO_Duration == 0) && (Proc[Current].IO_BURST > 0))
            {
                CPUBurstI = Proc[Current].CPU_WITH_IO;
            }
            else
            {
                CPUBurstI = Proc[Current].CPU_BURST;
            }
            SeqAdd(SIM);
            printf("CPU loading job %i : CPU burst (%i) IO burst (%i) \n",Proc[Current].P_ID, CPUBurstI, Proc[Current].IO_BURST - Proc[Current].IO_Duration);
        }
    }

    // Checks the process data if this is it first time in the CPU
    if(Proc[Current].CPU_Duration == 1)
    {
        Proc[Current].ResponseTime = SIM->Time;
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
            if((Proc[Current].IO_Duration == 0) && (Proc[Current].IO_BURST > 0))
            {
                CPUBurst = Proc[Current].CPU_WITH_IO;
            }
            else
            {
                CPUBurst = Proc[Current].CPU_BURST;
            }
            SeqAdd(SIM);
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
            if((Proc[Current].IO_Duration == 0) && (Proc[Current].IO_BURST > 0))
            {
                CPUBurst = Proc[Current].CPU_WITH_IO;
            }
            else
            {
                CPUBurst = Proc[Current].CPU_BURST;
            }
            SeqAdd(SIM);
            printf("CPU loading job %i: CPU burst(%i) IO burst(%i)\n",Proc[Current].P_ID, CPUBurst-Proc[Current].CPU_Duration, Proc[Current].IO_BURST-Proc[Current].IO_Duration);
        }

    }
    else
    {
        if((SIM->Time%SIM->TimeInterval == 0) && (SIM->Time != 0))
        {
            int CPUBurst;
            if((Proc[Current].IO_Duration == 0) && (Proc[Current].IO_BURST > 0))
            {
                CPUBurst = Proc[Current].CPU_WITH_IO;
            }
            else
            {
                CPUBurst = Proc[Current].CPU_BURST;
            }

            printf("Servicing %s job %i: CPU burst(%i) IO burst(%i)\n",SIM->Schedule, Proc[Current].P_ID, CPUBurst - Proc[Current].CPU_Duration, Proc[Current].IO_BURST - Proc[Current].IO_Duration );

            if(SIM->Time%SIM->TimeInterval == 0)
            {
                Proc[Current].ReadyQueue = false;//quick and dirty way to make the display ready queue will not output the Process it is serving
                DisplayReadyQueue(Proc, SIM);
                Proc[Current].ReadyQueue = true;
            }

            Proc[Current].CPU_Duration++;
            return true;

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
    int pos;//putting on the wizard hat
    //int Current = -1;//-1 acts as a error if the next for cant find the process


//    if(SIM->Time == 0)//indicates start of simulation
//    {
//        DisplayDeviceQueue(Proc, SIM);
//    }

//    if(SIM->IOProc > 0 && SIM->IO_Current == -1)
//    {
//        SIM->IO_Current = NextIO(Proc, SIM);
//    }

//    if(SIM->IO_Current == -1)//returns false since there is no more IO so it is finished
//    {
//        return false;
//    }

    for( pos=0; pos<SIM->TotalProc; pos++)//check to see what process is in the IO Queue
    {
        if(Proc[pos].DeviceQueue == true) //search to find which Process it is serving
        {
//            //Proc[pos].InIO == true;//indicates it is in the IO
//            if(Proc[pos].IO_Duration >= Proc[pos].IO_BURST)
//            {
//                Proc[pos].ReadyQueue = true; //Added to the Ready Queue
//                SIM->RQProc++;
//                Proc[pos].DeviceQueue = false; //removed from the Device Queue
//                SIM->IOProc--;
//
//                //SIM->CPU_Current = NextIO(Proc, SIM);//grabs the next on the queue
//
//            }
            Proc[pos].IO_Duration++;//increment the duation in the IO
        }
    }
//
//    if(Current == -1)//returns false: cant Find the current Process in the queue
//    {
//        return false;
//    }


    //Does all what it needs for the Current Process
    //Proc[Current].IO_Duration++;

    // Checks the process data. If there's a program that has finished its IO burst but needs to finish its IO, it moves it to the device queue.


    if(SIM->Time%SIM->TimeInterval == 0)
    {
        if(SIM->IOJFinished != -1)
        {
            int pos;
            for( pos=0; pos<SIM->TotalProc; pos++)//check each Process to see
            {
                if(Proc[pos].P_ID == SIM->IOJFinished) //search to find which Process it is serving
                {
                    break;
                }
            }

            printf("JOB %i finished I/O burst\n",Proc[pos].P_ID);

            SIM->IOJFinished = -1;
        }
        DisplayDeviceQueue(Proc, SIM);
    }
    else
    {
        if(SIM->IOJFinished != -1)
        {
            SIM->IOJFinished = -1;
        }
    }

    return true;
}

bool IsProcComplete(PROCESS Proc[], SIMULATION *SIM)
{
    int pos;
    for( pos=0; pos<SIM->TotalProc; pos++)
    {
        if(Proc[pos].Complete == false)
        {
            return true;
        }

    }
    return false;
}

int NextQueue(PROCESS Proc[], SIMULATION *SIM)
{
    int pos;
//    int i;
//    int Current = CPUPIDtoPOS(Proc, SIM);
//
//    for(i=1/*next process*/; i<SIM->TotalProc-1; i++) //checks the rest of the process
//    {
//        if(Proc[(i+Current)%SIM->TotalProc].ReadyQueue == true) //checks the next proc on the list to see if it needs to be in the Que
//        {
//            return Proc[(i+Current)%SIM->TotalProc].P_ID; //return the PID
//        }
//    }

    for(pos = 0; pos < SIM->TotalProc; pos++)
    {
        if(Proc[pos].ReadyQueue == true)
        {
            return Proc[pos].P_ID;
        }
    }

    return -1;//means it checked and there is no queues left to run
}

//int NextIO(PROCESS Proc[], SIMULATION *SIM)
//{
//    int i;
//    int Current = IOPIDtoPOS(Proc, SIM);
//
//    for(i=1/*next process*/; i<SIM->TotalProc-1; i++) //checks the rest of the process
//    {
//        if(Proc[(i+Current)%SIM->TotalProc].DeviceQueue == true) //checks the next proc on the list to see if it needs to be in the Que
//        {
//            return Proc[(i+Current)%SIM->TotalProc].P_ID;
//        }
//    }
//
//    return -1;//means it checked and there is no queues left to run
//}

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

//int IOPIDtoPOS(PROCESS Proc[],SIMULATION *SIM)//this will convert PID to the array position
//{
//    int pos;
//    for( pos=0; pos<SIM->TotalProc; pos++)//check each Process to see
//    {
//        if(Proc[pos].P_ID == SIM->IO_Current) //search to find which Process it is serving
//        {
//            return pos;
//        }
//    }
//    return -1; //error cant find
//}

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

void SeqAdd(SIMULATION *SIM)
{
    char TMP[5];
    int CPU_ID = SIM->CPU_Current;
    if(SIM->SeqOfProc[0] == '\0')
        sprintf(TMP,"%i",CPU_ID);
    else
        sprintf(TMP,"-%i",CPU_ID);

    strcat(SIM->SeqOfProc,TMP);
}

void FinalReport(PROCESS Proc[],SIMULATION *SIM)
{
    printf("\nFinal report for %s algorithm.\n\n",SIM->Schedule);

    //calculate throughput (total num of proc / time)
    double throughput = SIM->TotalProc/(double)SIM->Time;
    printf("THROUGHPUT = %.8g\n\n",throughput);

    //Process the wait time and add the total time
    double TotalTimeWaited = 0;
    int pos;

    //Sort the Array by PID
    SortPID(Proc, SIM);

    printf("Process ID Wait Time\n");

    for(pos = 0; pos < SIM->TotalProc; pos++)
    {
        printf("%-5i     	 %-5i\n",Proc[pos].P_ID, Proc[pos].ResponseTime);
        TotalTimeWaited+= Proc[pos].ResponseTime;
    }
    printf("AVERAGE WAITING TIME = %g\n\n", TotalTimeWaited/(double)pos);

    printf("CPU UTILIZATION = %g\%\n\n",((SIM->Time-SIM->CPU_Idle)/(double)SIM->Time)*100);

    printf("SEQUENCE OF PROCESSES IN CPU: %s\n\n", SIM->SeqOfProc);

    //Process the turnaroundtime
    double TurnAroundTime = 0;
    printf("Process ID  Turnaround Time\n");
    for(pos = 0; pos < SIM->TotalProc; pos++)
    {
        printf("%-5i     	 %-5i\n",Proc[pos].P_ID, Proc[pos].TurnAroundTime);
        TurnAroundTime=TurnAroundTime + Proc[pos].TurnAroundTime;
    }
    printf("AVERAGE TURNAROUND TIME = %g\n", TurnAroundTime/(double)SIM->TotalProc);

}

void SortPID(PROCESS Proc[],SIMULATION *SIM)
{
    int i, j, Total = SIM->TotalProc;

    for(i=0; i < Total; i++)
    {
        for(j=0; j < Total-1; j++)
        {

            if(Proc[j].P_ID > Proc[j+1].P_ID)
            {
                PROCESS tmp = Proc[j];
                Proc[j] = Proc[j+1];
                Proc[j+1] = tmp;
            }
        }
    }

}

void PCheckSort(PROCESS Proc[], SIMULATION *SIM)
{
    if(SIM->CPU_Current == -1)
    {
        return;
    }
    int Current = CPUPIDtoPOS(Proc, SIM);
    int Next = NextQueue(Proc, SIM);//return position of next CPU
    if(Next == -1)
    {
        return; //There is no easter bunny. no more
    }

    int CPUBurst1, CPUBurst2;
    if((Proc[Current].IO_BURST > 0))
    {
        CPUBurst1 = Proc[Current].CPU_WITH_IO;
    }
    else
    {
        CPUBurst1 = Proc[Current].CPU_BURST;
    }
    CPUBurst1-=Proc[Current].CPU_Duration;

    if((Proc[Next].IO_BURST > 0))
    {
        CPUBurst2 = Proc[Next].CPU_WITH_IO;
    }
    else
    {
        CPUBurst2 = Proc[Next].CPU_BURST;
    }
    CPUBurst2-=Proc[Next].CPU_Duration;

    if(CPUBurst1 > CPUBurst2)
    {
        PROCESS tmp = Proc[Current];
        Proc[Current] = Proc[Next];
        Proc[Next] = tmp;
        SIM->CPU_Current = Proc[Current].P_ID;
    }

    return;
}
