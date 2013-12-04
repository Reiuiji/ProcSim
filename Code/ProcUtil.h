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
    int WaitTime;//waiting time
    int FinishTime;//time when process finish
    int CPU_WITH_IO;//half the CPU time for IO executing hald way of the CPU Burst.
    bool Complete;//yay process is complete
    bool InCPU;//indicate that the Process is in the CPU
    bool InIO;//indicates that the Process is in the IO
    bool ReadyQueue;//your in the ready queue
    bool DeviceQueue;//your in the device queue

} PROCESS;

typedef struct SimulationInfo
{
    int TimeInterval;//snapshot time
    int Time;//simulate time
    int TotalProc;//total Prcesses in the simulation
    int RQProc; //number of Processes in the ready Queue
    int IOProc; //number of Processes in the IO Queue

} SIMULATION;

//functions
int InputFromFile(PROCESS Proc[], FILE *InputFile);
void ListProcess (PROCESS Proc[],SIMULATION SIM);
void SnapShot(PROCESS Proc[], SIMULATION SIM);//, char **);

void DisplayReadyQueue(PROCESS Proc[],SIMULATION SIM);
void DisplayDeviceQueue(PROCESS Proc[],SIMULATION SIM);

int Array_test(FILE* INPUT,SIMULATION SIM);


#endif MY_HEADER_H
