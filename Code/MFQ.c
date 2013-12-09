//Get all 3 queues
//Get arrival times
//Get Burst Times
//Measure Process Aging
//Plan intervals to transfer processes

#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include"ProcUtil.h"
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )



int MFQ(PROCESS Proc[], SIMULATION *Sim);
void MFQSort(PROCESS Proc[], SIMULATION *Sim);
void IO_MFQ(PROCESS Proc[], SIMULATION *Sim);
FIFO* Queue1;
FIFO* Queue2;
FIFO* Queue3;
/*Getting burst times from ReadyQueue
Get divide into three queues as a result
Place processes with burst time>3 on queue 1
Place processes with burst times between 3 and 8 on queue 2
Place processes with burst times greater than 8 on queue3
Use RR to sort queue 1 and 2. 
Use FCFS to sort queue3
Place sorted queues on IO queue(concatenate) in order */

int MFQ(PROCESS Proc[], SIMULATION *Sim)
{
    bool DEBUG = false;
    printf("/*********** First-Come-First-Serve Algorithm ***********/\n");
    Sim->Schedule = "FCFS";
    MFQSort(Proc, Sim);
     //setup ready current and IO current
    int current = Proc[0].P_ID;
    Sim->CPU_Current = current;//set at the first Process in the ready Queue
    Sim->IO_Current = -1;//there is none
    if(DEBUG == true)
    {
        ListProcess(Proc, Sim);
        ListSim(Sim);
    }

int i;
    while(IsProcComplete(Proc, Sim))
    {
        MFQSort(Proc, Sim);

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
 return 0;
}

void MFQSort(PROCESS Proc[], SIMULATION *Sim)
{
    int i, j, Total = Sim->TotalProc;

    for(i=0; i < Total; i++)
    {
        

            if((Proc[i].CPU_BURST<=3)&&(Proc[i+1].IO_BURST >= 1))
            {
              //Place Proc[i] on queue1
               F_ADD(Queue1,Proc[i]);
                    

            }
            else if((Proc[i].CPU_BURST<=8)&&(Proc[i].CPU_BURST>3)&&(Proc[i+1].IO_BURST >= 1))
            {
              //Place Proc[i] on queue2
              F_ADD(Queue2,Proc[i]);      

            }
            else if((Proc[i].CPU_BURST>8)&&(Proc[i+1].IO_BURST >= 1))
            {
              //Place Proc[i] on queue3
              F_ADD(Queue3,Proc[i]);
                     
            }
            
            
            if(Proc[i].P_ID==Proc[i+1].P_ID){
            printf("Two different processes cannot have the same ID number!!! \n");
            }
        }
        
        //Round Robin call for queue1 and queue2
        RoundRobin(Queue1, *SIM, 3);
        RoundRobin(Queue2, *SIM, 3);
        //FCFS call for queue 3
        FCFS(Queue3, *SIM);
        //Concatenate all 3 queues
    }

}

 queue1



}
