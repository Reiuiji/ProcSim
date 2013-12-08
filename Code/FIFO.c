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
            return ItemPtr;
        }
        temp = temp->next;
        pos++;
    }
    return NULL;
}
