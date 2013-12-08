#ifndef _STACK_H
#define _STACK_H

//For Boolean
#include <stdbool.h>

typedef char SElement;

typedef struct
{
  SElement *contents;
  int TOTAL;//maxsize
  int TOP;
} STACK;

void S_Init(STACK *SPtr, int TOTAL);
void S_Destroy(STACK *SPtr);
void S_Push(STACK *SPtr, SElement ENode);
SElement S_POP(STACK *SPtr);
bool S_Empty(STACK *SPtr);
bool S_Full(STACK *SPtr);

#endif
