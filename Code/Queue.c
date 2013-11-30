#include "Queue.h"

//===============================
//main Queue Functions
//===============================

/*	================= QUEUE_Create ================
	  Allocates dynamic memory for an QUEUE Stack
	  and returns its address

	   Pre    NULL
	   Post   Queue is allocated or error returned
	   Return Queue pointer; null if memory overflow

*/
QUEUE* QUEUE_Create (void)
{
    QUEUE* Que;

    //allocates memory for the Que
    Que = (QUEUE*) malloc (sizeof (QUEUE));
    if (Que)
    {
        //set the Que to point to null with 0 for count
        Que->NUM_P    = 0;
        Que->TOP     = NULL;
        Que->BOT     = NULL;
    }

    return Que;
}// End QUEUE_Create

/*	================= QUEUE_Insert ===================
      This function inserts new data into the Queue.

	   Pre    Que is a pointer to QUEUE structure
	   Post   data inserted or memory overflow
	   Return Success (true) or Overflow (false)

*/
bool QUEUE_Insert (QUEUE* Que, void* dataPtr)
{
    PROCNODE* newPtr;

    newPtr = (PROCNODE*)malloc(sizeof(PROCNODE));
    if (!newPtr)
        return false;

    newPtr->PROCESS = dataPtr;
    newPtr->NEXT    = NULL;
    newPtr->PREV    = NULL; //will set at insert

    if (Que->NUM_P == 0)
    {
        Que->TOP  =  newPtr;
        Que->BOT  =  newPtr;
    }
    else
    {
        _insert(Que->TOP, newPtr);
    }

    (Que->NUM_P)++;
    return true;
}// End QUEUE_Insert

/*	==================== _insert ====================
	  This function insert into the end of the Queue.

	   Pre    Application has called QUEUE_Insert, which
	          passes the data pointer
	   Post   Data have been inserted
	   Return pointer to [potentially] new Process Node

*/
static PROCNODE* _insert (PROCNODE* PNode, PROCNODE* newPtr)
{
    if (!PNode->NEXT)// if next PNode is null then insert here
    {
        newPtr->PREV=PNode;
        PNode->NEXT=newPtr;
        return PNode;
    }

    PNode->NEXT = _insert(PNode->NEXT, newPtr);
    return PNode;

}	// end _insert


/* ================== QUEUE_Delete ==================
	This function deletes a PROCNODE from the Queue

	   Pre    Queue initialized--null Queue is OK
	          deletekey is pointer to data structure
              containing key to be deleted

	   Post   PROCNODE deleted and its space recycled
	          -or- An error code is returned
	   Return Success (true) or Not found (false)
*/
bool QUEUE_Delete (QUEUE* Que, int PID)
{
    bool  success;
    PROCNODE* newPNode;

    newPNode = _delete (Que->TOP, PID, &success);
    if (success)
    {
        Que->TOP = newPNode;
        (Que->NUM_P)--;
        if (Que->NUM_P == 0)
            // Tree now empty
            Que->TOP = NULL;
    }
    return success;
}  // end QUEUE_Delete

/*	==================== _delete ====================
	  Deletes PROCNODE from the QUEUE

	   Pre    QUEUE initialized--null QUEUE is OK.
	          dataPtr contains key of PROCNODE to be deleted
	   Post   PROCNODE is deleted and its space recycled
	          -or- if key not found, QUEUE is unchanged
	   Return success is true if deleted; false if not found
	          pointer to PNode

*/
static PROCNODE* _delete (PROCNODE* PNode, int PID, bool* success)
{
    PROCNODE* dltPtr;
    PROCNODE* exchPtr;
    void* holdPtr;

    if (!PNode) // Could not Find it
    {
        *success = false;
        return NULL;
    }

    if(PNode->PROCESS->P_ID =! PID)//check if the PID equal
    {
        PNode->NEXT  = _delete ( PNode->NEXT, PID, success);
    }
    else
    {
        dltPtr = PNode;

        if(!PNode->NEXT) //Nothing next
        {
            free(PNode->PROCESS);
            free(dltPtr);
            *success = true; //yay removed with sucess
            return NULL;
        }
        else //there is stuff next on the list, So take out the prco and link the others
        {
            PNode->NEXT->PREV = PNode->PREV; //set up the back loop
            exchPtr = PNode->NEXT;//point to the next process
            free(PNode->PROCESS);
            free(dltPtr);
            return exchPtr;//return the link to the next process
        }
    }

    return PNode;
}	// _delete

/*	==================== QUEUE_Retrieve ===================
	Retrieve PROCNODE searches QUEUE for the PROCNODE containing
	the requested PID and returns pointer to its data.

	   Pre     QUEUE has been created (may be null)
	           data is pointer to data structure
	                containing PID to be located
	   Post    QUEUE searched and data pointer returned
	   Return  Address of matching PROCNODE returned
	           If not found, NULL returned

*/
PROCESS* QUEUE_Retrieve (QUEUE* Que, int PID)
{
	if (Que->TOP)
	    return _retrieve (PID, Que->TOP);
	else
	    return NULL;
}	// QUEUE_Retrieve

/*	===================== _retrieve =====================
	Searches QUEUE for PROCNODE containing the PID
	   Pre     _retrieve passes QUEUE, dataPtr, PNode
	           dataPtr is pointer to data structure
	              containing PID to be located
	   Post    QUEUE searched; data pointer returned
	   Return  Address of data in matching PROCNODE
	           If not found, NULL returned
*/
static PROCESS* _retrieve (int PID, PROCNODE* PNode)
{
	if (PNode)
	    {

			if (PNode->PROCESS->P_ID == PID )
                return PNode->PROCESS;
			else
                return _retrieve(PID, PNode->NEXT);
	    }
	else
	    return NULL;
}	// _retrieve

/*	=================== QUEUE_Traverse ===================
	Process QUEUE using inorder traversal.
	   Pre   QUEUE has been created (may be null)
	         process ÒvisitsÓ PROCNODEs during traversal
	   Post  PROCNODEs processed in LNR (inorder) sequence
*/
void QUEUE_Traverse (QUEUE* Que, void (*process) (void* dataPtr))
{
	_traverse (Que->TOP, process);
	return;
}  // end QUEUE_Traverse

/*	=================== _traverse ===================
	Inorder QUEUE traversal. To process a PROCNODE, we use
	the function passed when traversal was called.
	   Pre   QUEUE has been created (may be null)
	   Post  All PROCNODEs processed
*/
void _traverse (PROCNODE* PNode, void (*process) (void* dataPtr))
{
	if  (PNode)
		{
			process   (PNode->PROCESS);
			_traverse (PNode->NEXT, process);
		}
	return;
}  // _traverse


/*	=================== QUEUE_Empty ==================
	Returns true if QUEUE is empty; false if any data.
	   Pre      QUEUE has been created. (May be null)
	   Returns  True if QUEUE empty, false if any data
*/
bool QUEUE_Empty (QUEUE* Que)
{
    return (Que->NUM_P == 0);
}	// QUEUE_Empty

/*	===================== QUEUE_Full ====================
	If there is no room for another PROCNODE, returns true.
	   Pre      QUEUE has been created
	   Returns  true if no room for another insert
	            false if room
*/
bool QUEUE_Full  (QUEUE* Que)
{
    PROCNODE* newPtr;

    newPtr = (PROCNODE*)malloc(sizeof (*(Que->TOP)));
    if(newPtr)
    {
        free(newPtr);
        return false;
    }
    else
        return false;
}	// QUEUE_Full

/*	=================== QUEUE_Count ==================
	Returns number of PROCNODEs in QUEUE.
	   Pre     QUEUE has been created
	   Returns QUEUE count
*/
int  QUEUE_Count (QUEUE* Que)
{
    return (Que->NUM_P);
}	// QUEUE_Count

/*	=============== QUEUE_Destroy ==============
	Deletes all data in QUEUE and recycles memory.
	The PROCNODEs are deleted by calling a recursive
	function to traverse the QUEUE in inorder sequence.
	   Pre      QUEUE is a pointer to a valid QUEUE
	   Post     All data and head structure deleted
	   Return   null head pointer
*/
QUEUE* QUEUE_Destroy (QUEUE* Que)
{
	if (Que)
		_destroy (Que->TOP);

	free (Que);
	return NULL;
}	// QUEUE_Destroy

/*	=============== _destroy ==============
	Deletes all data in QUEUE and recycles memory.
	It also recycles memory for the key and data PROCNODEs.
	The PROCNODEs are deleted by calling a recursive
	function to traverse the QUEUE in inorder sequence.
	   Pre      PNode is pointer to valid QUEUE/Node
	   Post     All data and head structure deleted
	   Return   null head pointer
*/
static void _destroy (PROCNODE* PNode)
{
	if (PNode)
	   {
	    _destroy (PNode->NEXT);
	    free (PNode->PROCESS);
	    free (PNode);
	   }
	return;
}	// _destroy


//===============================
//suplimental functions
//===============================

void DisplayContents(QUEUE* list)
{
    printf("+---------+---------+---------+---------+\n");
    printf("|PID      |CPU_BURST|IO_Burst |Priority |\n");
    QUEUE_Traverse(list, ListProcess);
    printf("+---------+---------+---------+---------+\n");
}

/*	=================== processStu =====================
	Print one student's data.
	    Pre  stu is a pointer to a student
	    Post data printed and line advanced
*/
void ListProcess (void* procPtr)
{
	PROCESS Proc;

	Proc = *(PROCESS*)procPtr;

	printf("| %-7i | %-7i | %-7i | %-7i |\n", Proc.P_ID, Proc.CPU_BURST, Proc.IO_BURST, Proc.PRIORITY);

	return;
}   //ListProcess


void SnapShot(int CurrentTime, int TimeInverval, QUEUE* list)
{

}

void ProcessFromFile(QUEUE* list, FILE *InputFile)
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

int Queue_test(FILE* INPUT)
{
printf("+Queue test+\n");
QUEUE*  test;
test = QUEUE_Create();
ProcessFromFile(test,INPUT);
DisplayContents(test);

test = QUEUE_Destroy (test);
printf("-Queue test-\n");
return 0;
}
