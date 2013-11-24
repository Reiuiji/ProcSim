#include <stdbool.h>

int main(int argc, char *argv[])
{
	//set the variables
	int Select;
	bool INTERACTIVE = false;


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
