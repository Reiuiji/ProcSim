//maintain all the queue functions
#include "ProcUtil.c"
#include <stdio.h>



//process node for the queue to hold each process in the list
typedef struct ProcNode
{
	struct Process *PROCESS;
	struct ProcNode *NEXT;
	struct ProcNode *PREV;
} PROCNODE;

//stucture for the process queue that will hold all the process
typedef struct Queue
{
	int NUM_P;  // how many processes are in the queue
	PROCNODE *TOP;  //points to top of the list
	PROCNODE *BOT;  //points to the bottom of the list
} QUEUE;

QUEUE* QUEUE_Create();//create the queue
QUEUE* QUEUE_Destroy (QUEUE* Que);//delete the queue

bool QUEUE_Insert (QUEUE* Que, void* Ptr);//insert to the queue
bool QUEUE_Delete (QUEUE* Que, int PID);//delete from the queue
PROCESS* QUEUE_Retrieve (QUEUE* Que, int PID);
void  QUEUE_Traverse (QUEUE* Que, void (*process)(void* dataPtr));
bool QUEUE_Empty (QUEUE* Que);
bool QUEUE_Full  (QUEUE* Que);
int  QUEUE_Count (QUEUE* Que);
static PROCNODE* _insert (PROCNODE* PNode, PROCNODE* newPtr);
static PROCNODE* _delete (PROCNODE* PNode, int PID, bool* success);
static PROCESS* _retrieve (int PID, PROCNODE* PNode);
static void _traverse (PROCNODE* PNode, void (*process) (void* dataPtr));
static void _destroy (PROCNODE* PNode);


void ListProcess (void* procPtr);
void ProcessFromFile(QUEUE* list, FILE *InputFile);
void SnapShot(int CurrentTime, int TimeInverval, QUEUE* list);
int Queue_test(FILE* INPUT);
