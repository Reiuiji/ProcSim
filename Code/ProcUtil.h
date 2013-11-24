
//process sturcture, will hold all the information for the process
typedef struct Process  
{
	int P_ID;
	int CPU_BURST;
	int IO_BURST;
	int PRIORITY;
	
} PROCESS;


//process node for the queue to hold each process in the list
typedef struct ProcNode
{
	struct Process *PROCESS;
	struct ProcNode *NEXT;
} PROCNODE;

//stucture for the process queue that will hold all the process
typedef struct Queue
{
	int NUM_P;  // how many processes are in the queue
	ProcNode *TOP;  //points to top of the list 
	ProcNode *BOT;  //points to the bottom of the list
} QUEUE;

	   

