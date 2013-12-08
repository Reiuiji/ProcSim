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
  int TimeQ = 0;//holds the TimeQuantum of the RR so it does not need to interfer with time on aquired cpu jobs finish

  ReadyQueue = F_PImport(Proc, Sim);
  IOQueue = F_Create();
  Complete = F_Create();

//Simulate CPU
//CurrentProc = F_DEL(ReadyQueue);

  while(!F_Empty(ReadyQueue) || !F_Empty(IOQueue))
    {
      if(CurrentProc != NULL)
        {
          CurrentProc->CPU_Duration++;//increment the current Proc
        }
      else
        {
          Sim->CPU_Idle++;
        }

      if(Sim->Time%Sim->TimeInterval == 0)
        {
          printf("\nt = %i\n",Sim->Time);
        }

      //Reset the CPU if the it hits the TimeQuantum or reached its CPU Burst
          if(TimeQ%TimeQuantum == 0 || (CurrentProc->CPU_BURST == CurrentProc->CPU_Duration) || ((CurrentProc->IO_BURST > 0) && (CurrentProc->CPU_BURST/2 == CurrentProc->CPU_Duration)))
            {

              if(CurrentProc != NULL && Sim->Time > 0)
                {
                  if(Sim->Time%Sim->TimeInterval == 0)
                    {
                      printf("JOB %i finished CPU burst\n",CurrentProc->P_ID);
                    }
                }

              if(((Sim->Time%Sim->TimeInterval) == 0) && (!F_Empty(ReadyQueue)))
                {
                  printf("CPU loading job %i: ",F_ATProc(ReadyQueue,0)->P_ID);
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

              if((!F_Empty(ReadyQueue)))
                {
                  DispBurst(F_ATProc(ReadyQueue,0));
                }

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


      //F_CheckIO(IOQueue, ReadyQueue, Complete, Sim);

      //runsIO
      //if(!F_RunIO(IOQueue, ReadyQueue, Sim))
      {
        printf("current state of device queue: ");
        F_DisplayContent(IOQueue);
        printf("\n");
      }




      Sim->Time++;

              if(Sim->Time == 80)
        {
          F_ListProc(ReadyQueue);
          F_ListProc(IOQueue);
          return;
        }

    }
  printf("Exiting\n");



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
  F_ListProc(ReadyQueue);
  F_ListProc(IOQueue);




//Exiting the RR
  F_Destroy(Complete);
  F_Destroy(IOQueue);
  F_Destroy(ReadyQueue);
  return 0;
}

