#include "ProcUtil.h"
#include "FIFO.h"

void RoundRobin(PROCESS Proc[], SIMULATION *Sim, int TimeQuantum);
int RR(PROCESS Proc[], SIMULATION *Sim);

int RR(PROCESS Proc[], SIMULATION *Sim)
{
  printf("/***********  Round-Robin Algorithm (time quantum 3)  ***********/\n");

  Sim->Schedule = "RR";

  RoundRobin(Proc,Sim, 3);
}


//return the CPU it needs to work with
//input
//
//
void RoundRobin(PROCESS Proc[], SIMULATION *Sim, int TimeQuantum)
{
  FIFO* ReadyQueue;
  FIFO* IOQueue;
  FIFO* Complete;
  PROCESS* CurrentProc;
  PROCESS* dataPtr;
  int pos, Count, TimeQ = 0;//holds the TimeQuantum of the RR so it does not need to interfer with time on aquired cpu jobs finish

  ReadyQueue = F_PImport(Proc, Sim);
  IOQueue = F_Create();
  Complete = F_Create();

//Simulate CPU
//CurrentProc = F_DEL(ReadyQueue);

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


      //Reset the CPU if the it hits the TimeQuantum or reached its CPU Burst

      if((CurrentProc == NULL))
        {
          printf("CPU WAITING...\n");
          printf("current state of ready queue: ");
          F_DisplayContent(ReadyQueue);
          printf("\n");
          TimeQ=1;
        }
      else
        {
          if((TimeQ%TimeQuantum == 0 ) || (CurrentProc->CPU_BURST == CurrentProc->CPU_Duration) || ((CurrentProc->IO_BURST > 0) && (CurrentProc->CPU_BURST/2 == CurrentProc->CPU_Duration)))
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
              TimeQ=1;
            }
          else
            {
              TimeQ++;
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

// Test functions
//    PROCESS* dataPtr = F_ATProc(ReadyQueue,5);
//    printf("AT 5: %i\n",dataPtr->P_ID);
//for(pos = 0; pos < 10; pos++)
//{
//    F_ADD(ReadyQueue,F_DELAT(ReadyQueue,5));
//    F_Wait(ReadyQueue);
//    //F_ADD(ReadyQueue,F_DEL(ReadyQueue));
//    F_ListProc(ReadyQueue);
//}
  //F_ADD(ReadyQueue,CurrentProc);
//  printf("Ready Queue:\n");
//  F_ListProc(ReadyQueue);
//  printf("Device Queue:\n");
//  F_ListProc(IOQueue);
  //printf("Complete:\n");
 // F_ListProc(Complete);

F_FinalReport(Complete, Sim);

//Exiting the RR
  F_Destroy(Complete);
  F_Destroy(IOQueue);
  F_Destroy(ReadyQueue);
  return 0;
}


