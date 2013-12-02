#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_PROCESSES 10

// Creates a structure
typedef struct Process
{
	int P_ID;
	int CPU_BURST;
	int IO_BURST;
	int PRIORITY;
	int POSITION;
} PROCESS;

// Begins the main program
int main()
{
	/* Initializes the structures */
	Process Q_Pos[10];
	Process temp;
	/* Initialize the values of the PID's, CPU Bursts, IO Bursts, and Priorities. */
	int P_ID_VAR[10] =		{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9},
	    CPU_BURST_VAR[10] = { 10,  8, 12,  2,  8,  6,  4, 16, 14,  2},
		IO_BURST_VAR[10] = 	{  4,  2,  0,  4,  3,  4,  0,  7,  0, 10},
		PRIORITY_VAR[10] = 	{  2,  1,  5,  4,  0,  2,  5,  5,  1,  1};
	/* This makes it so that the values are easily modifiable if necessary. */
	/* This represents the position in the queue. */
	int i=0, x=0, y=0;	// numbers for iteration

	/* Fills in the values of the PID's, CPU Bursts, IO Bursts, and Priorities into the structures. */
	for(i=0; i<NUM_PROCESSES; i++)
	{
		Q_Pos[i].P_ID =			P_ID_VAR[i];
		Q_Pos[i].CPU_BURST =	CPU_BURST_VAR[i];
		Q_Pos[i].IO_BURST =		IO_BURST_VAR[i];
		Q_Pos[i].PRIORITY =		PRIORITY_VAR[i];
	}
	/* Again, this goes with initializing the values into arrays to make it easy to modify. */

	/* Sorting Algorithm */
	for(x=0; x<NUM_PROCESSES; x++)
	{
		for(y=0; y<NUM_PROCESSES-1; y++)
		{
			/* Rather than checking the Process ID, this is checking the Position in the fake Queue.
			This makes it a lot easier to move things around in the queue and sort it out.
			It checks if the current position has a higher CPU burst value than the one above it.
			if it does, it puts the values into a temporary struct and moves the values. */
			if(Q_Pos[y].CPU_BURST > Q_Pos[y+1].CPU_BURST)
			{
				temp = Q_Pos[y];
				Q_Pos[y] = Q_Pos[y+1];
				Q_Pos[y+1] = temp;
			}
		}
	}

	for(i=0; i<NUM_PROCESSES; i++)
	{
		printf("Position: %2d Process %2d: CPU_BURST: %2d\n", i, Q_Pos[i].P_ID, Q_Pos[i].CPU_BURST);
	}
	return 0;
}
