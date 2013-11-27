#include "ProcUtil.h"
#include <stdio.h>
#include <stdbool.h>

QUEUE* QUEUE_Create();
QUEUE* QUEUE_Destroy();

bool QUEUE_Insert (QUEUE* Q, void* Ptr);
bool QUEUE_Delete (QUEUE* Q, void* deletekey);

void ProcessList(QUEUE* list, FILE *InputFile);


void Process


void ProcessList(QUEUE* list, FILE *InputFile)
{
    int pid,cpuburst, ioburst, priority;

    PROCESS* ProcessPtr;

    while( fscanf(InputFile, "%i %i %i %i", &pid, &cpuburst, &ioburst, &priority) == 4)
    {
        ProcessPtr = (PROCESS*)malloc (sizeof(PROCESS));

        if(!ProcessPtr)
            printf("Memory Overflow while adding process"), exit(101);

        ProcessPtr->P_ID = pid;
        ProcessPtr->CPU_BURST = cpuburst;
        ProcessPtr->IO_BURST = ioburst;
        ProcessPtr->PRIORITY = priority;

        QUEUE_Insert(list, ProcessPtr);


    }

}
