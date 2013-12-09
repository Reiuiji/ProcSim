#include <stdbool.h>
#include "ProcUtil.h"

int main(int argc, char *argv[])
{
    //set the variables
    int Select = 0;
    bool INTERACTIVE = false;
    bool test = false;
    SIMULATION* SIMINFO;
    FILE *DATA;
    if(argc !=5)
    {
        printf("+===================================+\n");
        printf("|              ProcSim              |\n");
        printf("|===================================|\n");
        printf("|  What type of simulation?         |\n");
        printf("|----+------------------------------|\n");
        printf("|  1 |  First Come First Server     |\n");
        printf("|  2 |  Shortest Job First          |\n");
        printf("|  3 |  Shortest Job Remaining      |\n");
        printf("|  4 |  Round-Robin                 |\n");
        printf("|  5 |  Priority                    |\n");
        printf("|----|--Multi-level Feedback Queue  |\n");
        printf("+----+------------------------------+\n\n\n\n");
        printf("ProcSim <Input File> <Num of Processes> <Snapshot Time Interval> <Select>\n");
        return -1;
    }

    if ((DATA=fopen(argv[1],"rt")) == NULL)
    {
        printf("Sorry Could not find the File\nIt might have ran away from you!\nmake sure it is in the same directory as me(Program)\n");
        printf("I am going to skip the inputing from a file");
        exit(0);
    }

    Select = atoi(argv[4]);

//setup the Data
    SIMINFO= (SIMULATION*) malloc (sizeof (SIMULATION));
    SIMINFO->IOProc = 0;
    SIMINFO->RQProc = 0;
    SIMINFO->Time = 0;
    SIMINFO->CPU_Idle = 0;
    SIMINFO->IOJFinished = -1;//indicate no jobs finished
    SIMINFO->TotalProc = atoi(argv[2]);
    SIMINFO->TimeInterval = atoi(argv[3]);
    SIMINFO->PCheck = false;

    sprintf(SIMINFO->SeqOfProc, ":");
    PROCESS Proc[SIMINFO->TotalProc];
    SIMINFO->RQProc = InputFromFile(Proc,DATA);
    SIMINFO->IOProc = 0;
    //ListProcess(Proc,SIMINFO);

//just uncomment what function you need

if(Select == 1)
{
    FCFS(Proc, SIMINFO);
}
if(Select == 2)
{
    SJF(Proc, SIMINFO);
}
if(Select == 3)
{
    SJR(Proc, SIMINFO);
}
if(Select == 4)
{
    RR(Proc, SIMINFO);
}
if(Select == 5)
{
    PS(Proc,SIMINFO);
}
if(Select == 6)
{
    //Not Implemented
}


    if(test == true)
    {
        //Array_test(DATA,total);
    }

    //Interactive Mode
    if(INTERACTIVE == true)
    {
        //main menu for the ProSim functions
        printf("+===================================+\n");
        printf("|              ProcSim              |\n");
        printf("|===================================|\n");
        printf("|  What type of simulation?         |\n");
        printf("|----+------------------------------|\n");
        printf("|  1 |  First Come First Server     |\n");
        printf("|  2 |  Shortest Job First          |\n");
        printf("|  3 |  Shortest Job Remaining      |\n");
        printf("|  4 |  Round-Robin                 |\n");
        printf("|  5 |  Priority                    |\n");
        printf("|  6 |  Multi-level Feedback Queue  |\n");
        printf("|  x |  Exit the program            |\n");
        printf("+----+------------------------------+\n");

    }

    return 0;
}
