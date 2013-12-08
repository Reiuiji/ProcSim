#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void S_Init(STACK *SPtr, int TOTAL)
{
  SElement *NewContents;
  NewContents = (SElement *)malloc(sizeof(SElement) * TOTAL);

  if (NewContents == NULL)
    {
      printf("[Error]: Not Enought Memory.\n");
      exit(1);
    }

  SPtr->contents = NewContents;
  SPtr->TOTAL = TOTAL;
  SPtr->TOP = -1;  //indicate that there is nothing in the STACK
}

void S_Destroy(STACK *SPtr)
{
  free(SPtr->contents); //delete the Data in the STACK
  SPtr->contents = NULL;
  SPtr->TOTAL = 0;
  SPtr->TOP = -1;  //STACK is now Empty
}

void S_Push(STACK *SPtr, SElement ENode)
{
  if (S_Full(SPtr))
    {
      printf("[Error]: Can't PUSH | STACK is full.\n");
      exit(1);
    }

  SPtr->contents[++SPtr->TOP] = ENode;
}

SElement S_POP(STACK *SPtr)
{
  if (S_Empty(SPtr))
    {
      printf("[Error]: Can't POP | STACK is empty.\n");
      exit(1);
    }

  return SPtr->contents[SPtr->TOP--];
}

bool S_Empty(STACK *SPtr)
{
  if(SPtr->TOP < 0)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool S_Full(STACK *SPtr)
{
  if(SPtr->TOP >= SPtr->TOTAL - 1)
    {
      return true;
    }
  else
    {
      return false;
    }
}






