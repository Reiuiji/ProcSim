#include <stdbool.h>
#include "ProcUtil.h"

int main(int argc, char *argv[])
{
	//set the variables
	int Select;
	bool INTERACTIVE = false;
    bool test = false;
    FILE *DATA;
    if(argc !=4)
    {
        printf("ProcSim <Input File> <Num of Processes> <Snapshot Time Interval>\n");
        return -1;
    }

	if ((DATA=fopen(argv[1],"rt")) == NULL)
	{
		printf("Sorry Could not find the File\nIt might have ran away from you!\nmake sure it is in the same directory as me(Program)\n");
		printf("I am going to skip the inputing from a file");
		exit(0);
	}

//setup the Data
int total = atoi(argv[2]);
int snapshottime = atoi(argv[3]);
PROCESS Proc[total];
InputFromFile(Proc,DATA);
ListProcess(Proc,total);
PS(Proc,total,snapshottime);

    if(test == true)
    {
    Array_test(DATA,argv[2]);
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
