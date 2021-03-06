#ifndef _FIFO_H
#define _FIFO_H

//For Boolean
#include <stdbool.h>
#include "ProcUtil.h"

typedef struct fnode
{
  void *dataPtr;
  struct fnode *next;
} FNODE;

typedef struct Fifo
{
  FNODE *front;
  FNODE *rear;
  int count;
} FIFO;

FIFO* F_Create(void);
FIFO* F_Destroy(FIFO *fifo);

bool  F_ADD  (FIFO* fifo, void* ItemPtr);//add to the bottom
void* F_DEL  (FIFO* fifo);//remove from the top
void*  F_Front(FIFO* fifo);//returns what is in front
void*  F_Rear (FIFO* fifo);//returns what is in rear
int   F_Count(FIFO* fifo);//return how many
bool  F_Empty(FIFO* fifo);//check if empty
bool  F_Full (FIFO* fifo);//check if full


void* F_AT(FIFO* fifo, int at);//return what is at a specific spot
void* F_DELAT(FIFO* fifo, int at);//remove what is at a specific spot
PROCESS* F_ATProc(FIFO* fifo, int at);
//Functions
//FIFO Proc Import
FIFO* F_PImport(PROCESS Proc[], SIMULATION *Sim);
void F_ListProc(FIFO *fifo);
PROCESS* F_TO_Proc(FIFO* fifo);
void F_FinalReport(FIFO* fifo,SIMULATION *SIM);

void F_SeqAdd(int PID, SIMULATION *SIM);

#endif
