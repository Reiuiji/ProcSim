#ifndef _FIFO_H
#define _FIFO_H

//For Boolean
#include <stdbool.h>

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

#endif
