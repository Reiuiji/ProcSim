#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <stdbool.h>
#include <stdio.h>
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


//functions
int InputFromFile(PROCESS Proc[], FILE *InputFile);
void ListProcess (PROCESS Proc[],int Total);
void SnapShot(PROCESS Proc[], int CurrentTime, int TimeInverval);
int Array_test(FILE* INPUT,int Total);


#endif MY_HEADER_H
