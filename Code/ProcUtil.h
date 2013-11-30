#include <stdbool.h>
//process sturcture, will hold all the information for the process
typedef struct Process
{
	int P_ID; // PID
	int CPU_BURST; // CPU Burst time
	int IO_BURST; // IO Burst time
	int PRIORITY; //pritority
	int ResponseTime;
	int TurnAroundTime;
	int WaitTime;
	int FinishTime;
	bool Complete;
	bool InCPU;
	bool InIO;
	bool InQueue;

} PROCESS;






