#include <stdio.h>
#include "FIFO.h"

int fifotest(void);

int fifotest(void)
{
  FIFO* fifo;
  int* dataPtr;
  int i, value;

  //initilize the fifo
  fifo = F_Create();

  printf("FIFO: Testing Routine\n\n");

  printf("Inserting: ");

  for (i = 1; i <= 25; i++)
    {
      if (!(dataPtr = (int*) malloc (sizeof (int))))
        printf("Overflow in fillQueues\a\n"), exit(100);

      *dataPtr = value = rand() % 51;
      printf("%i ",value);
      F_ADD(fifo, dataPtr);
    }
  printf("\n");

  printf("Empty: %i\n",F_Empty(fifo));
  printf("FULL : %i\n",F_Full(fifo));

  printf("Count: %i\n",F_Count(fifo));

  printf("Front: %i\n",*(int*)F_Front(fifo));
  printf("Rear:  %i\n",*(int*)F_Rear(fifo));

  printf("At(0): %i\n",*(int*)F_AT(fifo,0));
  printf("At(1): %i\n",*(int*)F_AT(fifo,1));
  printf("At(5): %i\n",*(int*)F_AT(fifo,5));
  printf("At(10):%i\n",*(int*)F_AT(fifo,10));
  printf("At(15):%i\n",*(int*)F_AT(fifo,15));
  printf("At(20):%i\n",*(int*)F_AT(fifo,20));
  printf("At(25):%i\n",*(int*)F_AT(fifo,24));

  if(F_AT(fifo,26) == NULL)
    {
      printf("Nothing AT(26): NULL\n");
    }
  else
    {
      printf("At(26):%i\n",*(int*)F_AT(fifo,26));
    }

  printf("Return:    ");
  while (!F_Empty(fifo))
    {
      dataPtr = (int*)F_DEL (fifo);
      printf("%i ", *dataPtr);
    }
  printf("\n");
  printf("Empty: %i\n",F_Empty(fifo));

  F_Destroy(fifo);

  return 0;
}
