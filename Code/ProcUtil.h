#ifndef PROCUTIL//prevent this from being called multiple times
#define PROCUTIL

#include <stdbool.h>
#include <stdio.h>
//process sturcture, will hold all the information for the process
typedef struct Process
{
    int P_ID; // PID
    int CPU_BURST; // CPU Burst time
    int IO_BURST; // IO Burst time
    int PRIORITY; //pritority
    int ResponseTime;//Time When the process first response
    int TurnAroundTime;//time waiting for Process to access memory and complete execution of CPU
    int WaitTime;//waiting time
    int FinishTime;//time when process finish
    int CPU_WITH_IO;//half the CPU time for IO executing hald way of the CPU Burst.
    int CPU_Duration;//how long the process in the CPU
    int IO_Duration;//how long the process in the IO
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
    int CPU_Current;//[PID]Current Process in service by the CPU
    int IO_Current;//[PID]Current Process in Service by the IO
    int CPU_Idle;//how long the CPU is Idle
    int RQProc; //number of Processes in the ready Queue
    int IOProc; //number of Processes in the IO Queue
    int CPUJFinished; //[PID]signal to indicate that a process finished its job in the CPU
    int IOJFinished;//[PID] signal to indicate that a IO job is finished
    char ** Schedule; //what is the name of the Schedule Algorithm

} SIMULATION;

//functions

bool IsProcComplete(PROCESS Proc[], SIMULATION *SIM);
int NextQueue(PROCESS Proc[], SIMULATION *SIM);
//int NextIO(PROCESS Proc[], SIMULATION *SIM);
int PIDtoPOS(PROCESS Proc[],SIMULATION *SIM);
int CPUPIDtoPOS(PROCESS Proc[],SIMULATION *SIM);
//int IOPIDtoPOS(PROCESS Proc[],SIMULATION *SIM);

bool CheckCPU(PROCESS Proc[], SIMULATION *SIM);
bool CheckIO(PROCESS Proc[], SIMULATION *SIM);

void PreemptiveCheck(PROCESS Proc[], SIMULATION *SIM);

bool RunCPU(PROCESS Proc[], SIMULATION *SIM);
bool RunIO(PROCESS Proc[], SIMULATION *SIM);


int InputFromFile(PROCESS Proc[], FILE *InputFile);
void ListProcess (PROCESS Proc[],SIMULATION *SIM);
void ListSim(SIMULATION *SIM);

void SnapShot(PROCESS Proc[], SIMULATION *SIM);//, char **);

void DisplayReadyQueue(PROCESS Proc[],SIMULATION *SIM);
void DisplayDeviceQueue(PROCESS Proc[],SIMULATION *SIM);

int Array_test(FILE* INPUT,SIMULATION *SIM);


#endif PROCUTIL
