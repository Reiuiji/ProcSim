//Get arrival and service times for each process from queue.

//Get total time for each process and store in an array
//Then sort the processes based on arrival time. Use service time to set time intervals.

//Send back to process scheduler in proper order.
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include"ProcUtil.h"
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )
#include "FIFO.h"


int FCFS(PROCESS Proc[], SIMULATION *Sim);
void FCFSSort(PROCESS Proc[], SIMULATION *Sim);
void IO_FCFS(PROCESS Proc[], SIMULATION *Sim);

int FCFS(PROCESS Proc[], SIMULATION *Sim)
{
    printf("/***********  First-Come, First Served Algorithm ***********/\n");
    Sim->Schedule = "FCFS";

FIFO* ReadyQueue;
  FIFO* IOQueue;
  FIFO* Complete;
  PROCESS* CurrentProc;
  PROCESS* dataPtr;
int pos, Count;

  ReadyQueue = F_PImport(Proc, Sim);
  IOQueue = F_Create();
  Complete = F_Create();

CurrentProc = F_DEL(ReadyQueue);

  while(!F_Empty(ReadyQueue)|| !F_Empty(IOQueue) || (CurrentProc != NULL))
    {
      if(CurrentProc != NULL)
        {
          CurrentProc->CPU_Duration++;//increment the current Proc
        }
      else
        {
          Sim->CPU_Idle++;
        }
        if((F_Empty(ReadyQueue)) && (CurrentProc != NULL))
        {
            if(CurrentProc->CPU_BURST <= (CurrentProc->CPU_Duration ))
            {
                CurrentProc->TurnAroundTime = Sim->Time;
                F_ADD(Complete,CurrentProc);
                break;
            }
        }

      if(Sim->Time%Sim->TimeInterval == 0)
        {
          printf("\nt = %i\n",Sim->Time);
        }




      if((CurrentProc == NULL))
        {
          printf("CPU WAITING...\n");
          printf("current state of ready queue: ");
          F_DisplayContent(ReadyQueue);
          printf("\n");
        }
      else
        {
          if((CurrentProc->CPU_BURST == CurrentProc->CPU_Duration) || ((CurrentProc->IO_BURST > 0) && (CurrentProc->CPU_BURST/2 == CurrentProc->CPU_Duration)))
            {

              if(CurrentProc->CPU_BURST == CurrentProc->CPU_Duration)
                {
                  printf("JOB %i DONE\n", CurrentProc->P_ID);
                  CurrentProc->TurnAroundTime = Sim->Time;
                  F_ADD(Complete,CurrentProc);

                }

              if(CurrentProc != NULL && Sim->Time > 0)
                {
                  if(Sim->Time%Sim->TimeInterval == 0)
                    {
                      printf("JOB %i finished CPU burst\n",CurrentProc->P_ID);

                    }
                }

              if(((Sim->Time%Sim->TimeInterval) == 0) )
                {
                    if(!F_Empty(ReadyQueue))
                    {
                        printf("CPU loading job %i: ",F_ATProc(ReadyQueue,0)->P_ID);
                        //PROCESS* dataPtr = F_ATProc(ReadyQueue,5);
                        //    printf("AT 5: %i\n",dataPtr->P_ID);
                    }
                    else
                    {
                        printf("CPU loading job %i: ",CurrentProc->P_ID);
                        //F_SeqAdd(CurrentProc->P_ID, Sim);
                    }


                }

              //checks if it needs to go in the IO
              if((CurrentProc->IO_BURST > 0) && (CurrentProc->CPU_BURST/2 == CurrentProc->CPU_Duration))
                {
                  F_ADD(IOQueue,CurrentProc);

                }
              else if((Sim->Time >0 ) && !(CurrentProc->CPU_BURST == CurrentProc->CPU_Duration))
                {
                  F_ADD(ReadyQueue,CurrentProc);

                }


              DispBurst(F_ATProc(ReadyQueue,0));

              printf("current state of ready queue: ");
              F_DisplayContent(ReadyQueue);
              printf("\n");

              CurrentProc = F_DEL(ReadyQueue);
            }
          else
            {
              printf("Servicing %s job %i: ",Sim->Schedule,CurrentProc->P_ID);
              DispBurst(CurrentProc);
              printf("current state of ready queue: ");
              F_DisplayContent(ReadyQueue);
              printf("\n");
            }
          F_Wait(ReadyQueue);
        }



      //F_CheckIO(IOQueue, ReadyQueue, Complete, Sim);

      //runsIO
      if(!F_Empty(IOQueue))
        {
            Count = IOQueue->count;
          for(pos = 0; pos < Count; pos++)
            {
                dataPtr = F_DEL (IOQueue);
            if(dataPtr->IO_BURST == dataPtr->IO_Duration)
                {
                  printf("Job %i finished I/O burst\n",dataPtr->P_ID);
                  F_ADD(ReadyQueue,dataPtr);
                }
                else
                {
                    dataPtr->IO_Duration++;
                    F_ADD(IOQueue,dataPtr);
                }
            }
        }

      printf("current state of device queue: ");
      F_DisplayContent(IOQueue);
      printf("\n");

      Sim->Time++;

    }
}
//    bool DEBUG = false;
//    printf("/***********  First-Come-First-Serve Algorithm ***********/\n");
//    Sim->Schedule = "FCFS";
//    FCFSSort(Proc, Sim);
//     //setup ready current and IO current
//    int current = Proc[0].P_ID;
//    Sim->CPU_Current = current;//set at the first Process in the ready Queue
//    Sim->IO_Current = -1;//there is none
//    if(DEBUG == true)
//    {
//        ListProcess(Proc, Sim);
//        ListSim(Sim);
//    }
//    //SnapShot(Proc, Sim);
//
//
//    int i;
//    while(IsProcComplete(Proc, Sim))
//    {
//        FCFSSort(Proc, Sim);
//
//        //IO_SJF(Proc, Sim);
//        RunCPU(Proc, Sim);
//        RunIO(Proc, Sim);
//
//        Sim->Time++;
//        if(DEBUG == true)
//        {
//            ListProcess(Proc, Sim);
//            ListSim(Sim);
//        }
//
//        CheckCPU(Proc, Sim);
//        CheckIO(Proc, Sim);
//        //SnapShot(Proc, Sim);
//
//    }
//
//    return 0;
//}


//void FCFSSort(PROCESS Proc[], SIMULATION *Sim)
//{
//    int i, j, k, m, n, Total = Sim->TotalProc;
//
//    for(i=0; i < Total-1; i++)
//    {
//        for(j=0; j < Total-1; j++)
//        {
//
//            if((Proc[j].P_ID>Proc[j+1].P_ID)&&(Proc[j+1].IO_BURST >= 1))
//            {
//
//                    PROCESS tmp = Proc[j];
//                    Proc[j] = Proc[j+1];
//                    Proc[j+1] = tmp;
//
//            }
//          /*  m=Proc[ARRAY_SIZE(proc[])];
//            n=Proc[0];
//            for(k=m-1;k=m+n;k++){
//            Proc[k]=???
//            }
//
//            */
//            else if(Proc[j].P_ID==Proc[j+1].P_ID){
//            printf("Two different processes cannot have the same ID number!!! \n");
//            }
//        }
//    }
//
//}

/*PROCESS Proc[]         //proc must be global
int queue[]       //queue variable should be global
void FCFS(Proc[])  //Function to sort by arrival time


int FCFS(Proc[])  //Function to sort by arrival time{

for(int i=0;i=sizeof(Proc)-1;i++){
queue[i]=Proc[i];
return queue;
}
void main(){
    FCFS(Proc[]);
}

char arrival(queue)      //Function to get arrival time

void main(){
  arrival(file);
  FCFS(Proc[]);
}

FCFS(Proc[]){
  int s=ARRAY_SIZE(Proc);
  for(int j=0; j=s-1;j++){    //Sorting by process ID, not arrival time
   for(int i=0; i=s-1;i++){
      if(Proc[i]>Proc[i+1]){
        int temp=Proc[i];
        Proc[i]=Proc[i+1];
        Proc[i+1]=temp;
        }
      }

    }
}



  arrival(char queue1[]){


    //Somehow count characters to read in arrival times from file
    File *file;
    file=fopen("queue.c", r);
    //somehow read in arrival times

    return file;
  }
*/





