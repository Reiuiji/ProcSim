#include "FIFO.h"
#include <stdio.h>

FIFO* F_Create(void)
{
  FIFO* fifo;

  fifo = (FIFO*) malloc(sizeof (FIFO));

  if(fifo)
    {
      fifo->front = NULL;
      fifo->rear  = NULL;
      fifo->count = 0;
    }
  return fifo;
}

FIFO* F_Destroy(FIFO *fifo)
{
  FNODE* DelNode;

  if(fifo)
    {
      while(fifo->front != NULL)
        {
          free(fifo->front->dataPtr);
          DelNode = fifo->front;
          fifo->front = fifo->front->next;
          free(DelNode);
        }
      free(fifo);
    }
  return NULL;
}

bool F_ADD(FIFO* fifo, void* ItemPtr)
{
  FNODE* fnode;

  if(!(fnode = (FNODE*)malloc(sizeof(FNODE))))
    {
      return false;
    }

  fnode->dataPtr = ItemPtr;
  fnode->next    = NULL;

  if(fifo->count == 0)
    {
      fifo->front = fnode;
    }
  else
    {
      fifo->rear->next = fnode;
    }

  (fifo->count)++;

  fifo->rear = fnode;

  return true;
}

void* F_DEL (FIFO* fifo)
{
  void* ItemPtr;
  FNODE* DelNode;

  if(!fifo->count)
    {
      return NULL;
    }
  ItemPtr = fifo->front->dataPtr;
  DelNode = fifo->front;

  if(fifo->count == 1)//only one in the queue
    {
      fifo->rear = fifo->front = NULL;
    }
  else
    {
      fifo->front = fifo->front->next;
    }

  (fifo->count)--;
  free(DelNode);

  return ItemPtr;
}

void* F_Front(FIFO* fifo)
{
  void* ItemPtr;
  if(!fifo->count)
    {
      return NULL;
    }
  else
    {
      ItemPtr = fifo->front->dataPtr;
      return ItemPtr;
    }
}

void* F_Rear(FIFO* fifo)
{
  void* ItemPtr;
  if(!fifo->count)
    {
      return NULL;
    }
  else
    {
      ItemPtr = fifo->rear->dataPtr;
      return ItemPtr;
    }
}

int  F_Count(FIFO* fifo)
{
  return fifo->count;
}

bool F_Empty(FIFO* fifo)
{
  return (fifo->count == 0);
}

bool F_Full(FIFO* fifo)
{
  FNODE* temp;

  temp = (FNODE*)malloc(sizeof(*(fifo->rear)));
  if(temp)
    {
      free(temp);
      return false;
    }

  return true;
}

void* F_AT(FIFO* fifo, int at)
{
  FNODE* temp;
  if(fifo->count < at)//you wanted something beond what it had
    {
      return NULL;
    }

  temp = fifo->front;
  int pos = 0;//you at the first spot

  while (temp != NULL)
    {
      if(pos == at)
        {
          return temp;
        }
      temp = temp->next;
      pos++;
    }
  return NULL;
}

void* F_DELAT(FIFO* fifo, int at)
{
  void* ItemPtr;
  FNODE* temp;
  if(fifo->count < at)//you wanted something beond what it had
    {
      return NULL;
    }

  temp = fifo->front;
  int pos = 0;//you at the first spot

  while (temp != NULL)
    {
      if(pos == at)
        {
          ItemPtr = temp->dataPtr;

          if(fifo->count == 1)//only one in the queue
            {
              fifo->front = fifo->front->next;
            }
          else if(fifo->count == at)
            {
              fifo->rear = F_AT(fifo,at-1);//set fifo to point at the previous one
              fifo->rear->next = NULL;//set the new real to point null
            }
          else //it is in between
            {
              FNODE* temp2 = F_AT(fifo,at-1);
              temp2->next = temp2->next->next;
            }


          (fifo->count)--;
          free(temp);
          return ItemPtr;
        }
      temp = temp->next;
      pos++;
    }
  return NULL;
}

PROCESS* F_ATProc(FIFO* fifo, int at)
{
  FNODE* ItemPtr;
  ItemPtr = F_AT(fifo, at);
  if(ItemPtr != NULL)
    {
      return (PROCESS*) ItemPtr->dataPtr;
    }
  else
    {
      return NULL;
    }
}

FIFO* F_PImport(PROCESS Proc[], SIMULATION *Sim)
{
  PROCESS* dataPrt;
  FIFO* fifo;
  int pos;
  PROCESS value;

  fifo = F_Create();

//grab data from Proc and insert it into the list
  for(pos = 0; pos < Sim->TotalProc; pos++)
    {
      if(!(dataPrt = (PROCESS*) malloc(sizeof (PROCESS))))
        {
          printf("[Error]: Data Overflow\n");
          exit(100);
        }

      *dataPrt = Proc[pos];
      //printf("Inserted: %i\n",(dataPrt)->P_ID );
      F_ADD(fifo, dataPrt);
    }

  return fifo;

}

void F_ListProc(FIFO *fifo)
{
  int pos;
  bool FullDisplay = true;
  PROCESS* dataPtr;

  if(FullDisplay == false)
    {
      printf("+---------+---------+---------+---------+\n");
      printf("|PID      |CPU_BURST|IO_Burst |Priority |\n");
      for(pos = 0; pos < fifo->count; pos++)
        {
          dataPtr = F_ATProc(fifo,pos);
          if(dataPtr != NULL)
            {
              printf("| %-7i | %-7i | %-7i | %-7i |\n", dataPtr->P_ID, dataPtr->CPU_BURST, dataPtr->IO_BURST, dataPtr->PRIORITY);
            }

        }
      printf("+---------+---------+---------+---------+\n");
    }
  else
    {
      printf("+-----+---------+--------+--------+--------+-----+-----+------+-----+-----+-----+-----+-----+-----+\n");
      printf("| PID |CPU_BURST|IO_Burst|Priority|CPUwthIO|RTime|WTime|TATime|INCPU|IN IO|D Que|R Que|CPU D|IO D |\n");
      for(pos = 0; pos < fifo->count; pos++)
        {
          dataPtr = F_ATProc(fifo,pos);
          printf("| %-3i | %-7i | %-6i | %-6i | %-6i | %-3i | %-3i | %-4i | %-3i | %-3i | %-3i | %-3i | %-3i | %-3i |\n", dataPtr->P_ID, dataPtr->CPU_BURST, dataPtr->IO_BURST, dataPtr->PRIORITY, dataPtr->CPU_WITH_IO, dataPtr->ResponseTime, dataPtr->WaitTime, dataPtr->TurnAroundTime, dataPtr->InCPU, dataPtr->InIO, dataPtr->DeviceQueue, dataPtr->ReadyQueue, dataPtr->CPU_Duration, dataPtr->IO_Duration);
        }
      printf("+-----+---------+--------+--------+--------+-----+-----+------+-----+-----+-----+-----+-----+-----+\n");
    }

  return;
}

void F_Wait(FIFO* fifo)
{
  FNODE* temp;

  if(fifo->count == 0)//you wanted something beond what it had
    {
      return;
    }

  temp = fifo->front;

  while (temp != NULL)
    {
      ((PROCESS*)temp->dataPtr)->WaitTime++;
      temp = temp->next;
    }
  return;
}

void F_IODur(FIFO* fifo)
{
  FNODE* temp;

  if(fifo->count == 0)//you wanted something beond what it had
    {
      return;
    }

  temp = fifo->front;

  while (temp != NULL)
    {
      ((PROCESS*)temp->dataPtr)->IO_Duration++;
      temp = temp->next;
    }
  return;
}


void F_DisplayContent(FIFO* fifo)
{
  PROCESS* dataPtr;
  int pos;
  if(fifo->count == 0)
    {
      printf("EMPTY");
      return;
    }
  for(pos = 0; pos < fifo->count; pos++)
    {
      if(pos != 0)
        {
          printf("-");
        }
      dataPtr = F_ATProc(fifo,pos);
      printf("%i",dataPtr->P_ID);
    }
  return;
}

bool F_RunIO(FIFO* IOQue, FIFO* ReadyQue, SIMULATION *Sim)
{
  FNODE* temp;
  bool found = false;
  int pos = 0;
  if(IOQue->count == 0)//you wanted something beond what it had
    {
      return found;
    }

  //pluss all IO_Durations
  temp = IOQue->front;

  while (temp != NULL)
    {
      ((PROCESS*)temp->dataPtr)->IO_Duration++;
      temp = temp->next;
    }

  if(Sim->Time%Sim->TimeInterval == 0)
    {
      if(Sim->IOJFinished != -1)
        {
          int pos;
          for( pos=0; pos<Sim->TotalProc; pos++)//check each Process to see
            {
              if(F_ATProc(IOQue,pos)->P_ID == Sim->IOJFinished) //search to find which Process it is serving
                {
                  break;
                }
            }

          printf("JOB %i finished I/O burst\n",F_ATProc(IOQue,pos)->P_ID);

          Sim->IOJFinished = -1;
        }
      //F_ListProc(IOQue);
    }
  else
    {
      if(Sim->IOJFinished != -1)
        {
          Sim->IOJFinished = -1;
        }
    }

  return true;
//      //indicates that IO time is done
//      if(((PROCESS*)temp->dataPtr)->IO_Duration == ((PROCESS*)temp->dataPtr)->IO_BURST)
//        {
//          if((Sim->Time%Sim->TimeInterval) == 0)
//            {
//              printf("Job %i finished I/O burst\n",((PROCESS*)temp->dataPtr)->P_ID);
//            }
//          printf("current state of device queue: ");
//          F_DisplayContent(IOQue);
//          printf("\n");
//
//          F_ADD(ReadyQue,temp->dataPtr);//add Device to Ready
//          F_DELAT(IOQue,pos);
//          temp=F_AT(IOQue,pos-1);
//          found = true;
//        }
//      if(temp != NULL)
//        {
//          temp = temp->next;
//        }
//      pos++;
//
//  return found;
}

void F_CheckCPU(FIFO* IOQue, FIFO* ReadyQue, FIFO* Complete)
{
  int pos=0;
  for(pos = 0; pos < ReadyQue->count; pos++)
    {
      if( (F_ATProc(ReadyQue, pos))->CPU_BURST == (F_ATProc(ReadyQue,pos))->CPU_Duration )//finished all the CPU time required
        {
          if( (F_ATProc(ReadyQue, pos))->IO_BURST == (F_ATProc(ReadyQue, pos))->IO_Duration)
            {
              F_ADD(Complete,F_DELAT(ReadyQue,pos));
            }
          else
            {
              F_ADD(IOQue,F_DELAT(ReadyQue,pos));
            }
        }
      else if(( (F_ATProc(ReadyQue, pos))->CPU_BURST == (F_ATProc(ReadyQue, pos))->CPU_WITH_IO) && ((F_ATProc(ReadyQue, pos))->IO_BURST > 0))
        {
          F_ADD(IOQue,F_DELAT(ReadyQue,pos));
        }
    }
}

//void F_CheckIO(FIFO* IOQue, FIFO* ReadyQue)
//{
//  FNODE* temp;
//  temp = IOQue->front;
//  PROCESS* CurrentProc;
//  int pos = 0;
//
//  while (temp != NULL)
//    {
//
//      if(((PROCESS*) temp->dataPtr)->IO_BURST == ((PROCESS*) temp->dataPtr)->IO_Duration)//finished all the IO time required
//        {
//          CurrentProc = temp->dataPtr;
//
//          if(IOQue->count == 1)//only one in the queue
//            {
//              IOQue->front = IOQue->front->next;
//            }
//          else if((IOQue)->count == pos)
//            {
//              IOQue->rear = F_AT(IOQue,pos-1);//set IOQue to point at the previous one
//              IOQue->rear->next = NULL;//set the new real to point null
//            }
//          else //it is in between
//            {
//              FNODE* temp2 = F_AT(IOQue,pos-1);
//              temp2->next = temp2->next->next;
//            }
//
//
//          F_ADD(ReadyQue,CurrentProc);
//
//
//          (IOQue->count)--;
//          free(temp);
//        }
//        pos++;
//    }
//}

void F_CheckIO(FIFO* IOQue, FIFO* ReadyQue, FIFO* Complete, SIMULATION *Sim)
{
  int pos;
  for(pos = 0 ; pos < IOQue->count; pos++)
    {
      if((F_ATProc(IOQue, pos))->IO_BURST == (F_ATProc(IOQue, pos))->IO_Duration)//finished all the IO time required
        {
          if((F_ATProc(IOQue, pos))->CPU_BURST == (F_ATProc(IOQue, pos))->CPU_Duration)
            {
              F_ADD(Complete,F_DELAT(IOQue,pos));
            }
          else
            {
              F_ADD(ReadyQue,F_DELAT(IOQue,pos));
              if(Sim->IOJFinished == -1)
                {
                  Sim->IOJFinished = (F_ATProc(IOQue, pos))->P_ID;
                }
            }
        }
    }
}

void F_FinalReport(FIFO* fifo,SIMULATION *SIM)
{
  //Sort the Array by PID
  int pos;
  PROCESS Proc[fifo->count];

  for(pos = 0; pos < fifo->count; pos++)
  {
    Proc[pos] = *F_ATProc(fifo,pos);
  }
  FinalReport(Proc,SIM);
}

void F_SeqAdd(int PID, SIMULATION *SIM)
{
  char TMP[5];
  int CPU_ID = PID;
  if(strcmp(SIM->SeqOfProc," ") == 0)
    sprintf(TMP,"%i",CPU_ID);
  else
    sprintf(TMP,"-%i",CPU_ID);

  strcat(SIM->SeqOfProc,TMP);
}
