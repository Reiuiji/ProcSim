#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creates a structure
typedef struct Process
{
	int P_ID;
	int CPU_BURST;
	int IO_BURST;
	int PRIORITY;
	int CPU_WITH_IO;
} PROCESS;

// Prototype for the Sorting Algorithm
void SJFSort(PROCESS Proc[], int Total);

// Begins the main program
int main()
{
	/* Initializes the structures */
	PROCESS Q_Pos[10];

	/* Initialize the values of the PID's, CPU Bursts, IO Bursts, and Priorities. */
	int P_ID_VAR[10] =	{  0,  1,  2,  3,  4,  5,  6,  7,  8,  9},
    CPU_BURST_VAR[10] = { 10,  8, 12,  2,  8,  6,  4, 16, 14,  2},
    IO_BURST_VAR[10] =  {  4,  2,  0,  4,  3,  4,  0,  7,  0, 10},
    PRIORITY_VAR[10] = 	{  2,  1,  5,  4,  0,  2,  5,  5,  1,  1};
	/* This makes it so that the values are easily modifiable if necessary. */
	/* This represents the position in the queue. */
	int i=0, j=0, x=0, y=0, t=0, CPU_QUEUE, CPU_FLAG = 0, NUM_PROCESSES = 10, temp;	// numbers for iteration
	int LOADED_CPU_BURST, LOADED_IO_BURST, LOADED_CPU_WITH_IO;
	int DEVICE_CPU_BURST, DEVICE_IO_BURST;
	int READY_CPU_WITH_IO, READY_CPU_BURST, READY_IO_BURST;
	int LOP = 0;
	int READY_QUEUE[50] = {-1}, IO_QUEUE[50] = {-1}; // The queues. These are here because I'm bad at things.

	// inputs counters for each of the processes in the queues so it knows when to end.
	int READY_QUEUE_AMT = 0, CPU_QUEUE_amount = 0, IO_QUEUE_AMT = 0;

	READY_QUEUE_AMT = NUM_PROCESSES;

	/* Fills in the values of the PID's, CPU Bursts, IO Bursts, and Priorities into the structures. */
	for(i=0; i<NUM_PROCESSES; i++)
	{
		Q_Pos[i].P_ID =			P_ID_VAR[i];
		Q_Pos[i].CPU_BURST =	CPU_BURST_VAR[i];
		Q_Pos[i].IO_BURST =		IO_BURST_VAR[i];
		Q_Pos[i].PRIORITY =		PRIORITY_VAR[i];
		// This makes a note of whether or not the process will have to stop halfway in due to the IO burst.
		if(Q_Pos[i].IO_BURST > 0)
		{Q_Pos[i].CPU_WITH_IO =	(CPU_BURST_VAR[i]/2);}
		// If it doesn't, it sets the half burst time to -1.
		else
		{Q_Pos[i].CPU_WITH_IO = -1;}
	}

	// Before the processes are loaded into the Ready Queue, they're sorted.
    SJFSort(Q_Pos, NUM_PROCESSES);

	//Adds to the fake ready queue for the first time.
	for(x=0; x<NUM_PROCESSES; x++)
	{ READY_QUEUE[x] = Q_Pos[x].P_ID; }

/*====================================================================================================*/
/*====================================================================================================*/
/*====================================================================================================*/

	while(LOP<10)
	{
		if(CPU_FLAG == 1)
		{
			// Loads all of the values from the process in the CPU.
			for(i=0; i<NUM_PROCESSES; i++)
			{
				if(CPU_QUEUE == Q_Pos[i].P_ID)
				{
					LOADED_CPU_WITH_IO = Q_Pos[i].CPU_WITH_IO;
					LOADED_CPU_BURST = Q_Pos[i].CPU_BURST;
					LOADED_IO_BURST = Q_Pos[i].IO_BURST;
				}
			}

			// Checks the process data. If there's a program that has finished its CPU burst but needs to finish its IO, it moves it to the device queue.
			if((LOADED_CPU_BURST == 0) && (LOADED_IO_BURST > 0))
			{
				IO_QUEUE[IO_QUEUE_AMT] = CPU_QUEUE;
				IO_QUEUE_AMT++;
				CPU_QUEUE = -1;
				CPU_FLAG = 0;
			}

			// Checks the process data. If there's a program that has finished its CPU burst and has finished its IO burst, it gets removed.
			else if((LOADED_CPU_BURST == 0) && (LOADED_IO_BURST == 0))
			{
				CPU_QUEUE = -1;
				CPU_FLAG = 0;
			}

			// Checks the process data. If there's a program that has finished half of its CPU burst but needs to finish its IO, it moves it to the device queue.
			else if((LOADED_CPU_WITH_IO <= 0) && (LOADED_IO_BURST > 0))
			{
				IO_QUEUE[IO_QUEUE_AMT] = CPU_QUEUE;
				IO_QUEUE_AMT++;
				CPU_QUEUE = -1;
				CPU_FLAG = 0;
			}

			// Otherwise it should be in a situation where it just needs to run normally.
		}

		// Checks if there's anything in the IO queue
		if(IO_QUEUE_AMT >= 1)
		{
            for(i=0; i<IO_QUEUE_AMT;i++)
            {
                if(IO_QUEUE_AMT == 0)
                {
                    for(j=0; j<NUM_PROCESSES; j++)
                    {
                        // Goes through a cycle to grab the data for each of the Processes in the IO Queue
                        if(IO_QUEUE == Q_Pos[j].P_ID)
                        {
                            DEVICE_CPU_BURST = Q_Pos[j].CPU_BURST;
                            DEVICE_IO_BURST = Q_Pos[j].IO_BURST;
                        }
                    }
                }
				else
				{
					for(j=0; j<NUM_PROCESSES; j++)
					{
						// Goes through a cycle to grab the data for each of the Processes in the IO Queue
						if(IO_QUEUE[i] == Q_Pos[j].P_ID)
						{
							DEVICE_CPU_BURST = Q_Pos[j].CPU_BURST;
							DEVICE_IO_BURST = Q_Pos[j].IO_BURST;
						}
					}
				}

				// If there's a process in the IO queue that doesn't have any burst but has a CPU burst left
				if((DEVICE_IO_BURST == 0) && (DEVICE_CPU_BURST >=1))
				{
					// it moves it to the back of the ready queue and increases the counter
					READY_QUEUE[READY_QUEUE_AMT+1] = IO_QUEUE[i];
					READY_QUEUE_AMT++;

					// it then shifts over the entire IO queue
					for(j=i; j<IO_QUEUE_AMT; j++)
					{
						IO_QUEUE[j] = IO_QUEUE[j+1];
						IO_QUEUE[j+1] = -1;
					}
					IO_QUEUE_AMT--;
					// and it decrements so it doesn't skip any elements.
					//i--;
				}

				// if there is a process that has finished and doesn't have a CPU burst
				if((DEVICE_IO_BURST == 0) && (DEVICE_CPU_BURST == 0))
				{
					// it shifts everything and deletes the process.
					for(j=i; j<IO_QUEUE_AMT; j++)
					{
						IO_QUEUE[j] = IO_QUEUE[j+1];
						IO_QUEUE[j+1] = -1;
					}
					IO_QUEUE_AMT--;

					// and it decrements so it doesn't skip any elements.
					//i--;
				}
			}
		}

		if(CPU_FLAG == 0)
		{
			for(i=0; i<NUM_PROCESSES; i++)
			{
				if(READY_QUEUE[0] == Q_Pos[i].P_ID)
				{
					READY_CPU_WITH_IO = Q_Pos[i].CPU_WITH_IO;
					READY_CPU_BURST = Q_Pos[i].CPU_BURST;
					READY_IO_BURST = Q_Pos[i].IO_BURST;
				}
			}

			/* I need to make a way that if this happens, it keeps searching for a value */
			/* I don't want to use GOTO, but it would be easiest? */

			if((READY_CPU_BURST == 0) && (READY_IO_BURST >= 1))
			{
				IO_QUEUE[IO_QUEUE_AMT] = READY_QUEUE[0];
				for(i=0; i<READY_QUEUE_AMT; i++)
				{
					READY_QUEUE[i] = READY_QUEUE[i+1];
					READY_QUEUE[i+1] = -1;
				}
				READY_QUEUE_AMT--;
			}
			else if((READY_CPU_WITH_IO >= 1) || (READY_CPU_BURST >= 1))
			{
				CPU_QUEUE = READY_QUEUE[0];
				CPU_FLAG = 1;
				for(i=0; i<READY_QUEUE_AMT; i++)
				{
					READY_QUEUE[i] = READY_QUEUE[i+1];
					READY_QUEUE[i+1] = -1;
				}
				READY_QUEUE_AMT--;
			}
		}

		if(READY_QUEUE[0] != -1)
		{
			printf("Ready Queue: %d", READY_QUEUE[0]);
			for(i=1; i>READY_QUEUE_AMT; i++)
			{
					printf("-%d", READY_QUEUE[i]);
			}
			printf("\n");
		}
		if(IO_QUEUE[0] != -1)
		{
			printf("Device Queue: %d", IO_QUEUE[0]);
			for(i=1; i>IO_QUEUE_AMT; i++)
			{
					printf("-%d",IO_QUEUE[i]);
			}
			printf("\n");
		}
		if(CPU_QUEUE != -1)
		{
			printf("CPU Queue: %d\n\n", CPU_QUEUE);
		}

/* ------------------------------------------- */

		if(IO_QUEUE[0] != -1)
		{
			for(i=0; i<NUM_PROCESSES; i++)
			{
				for(j=0; j<IO_QUEUE_AMT; j++)
				{
					if(IO_QUEUE[i] == Q_Pos[j].P_ID)
					{
						Q_Pos[j].IO_BURST--;
					}
				}
			}
		}
		if(CPU_FLAG = 1)
		{
			for(i=0; i<NUM_PROCESSES; i++)
			{
				if(CPU_QUEUE == Q_Pos[i].P_ID)
				{
					if(Q_Pos[i].CPU_WITH_IO >= 1)
					{
						Q_Pos[i].CPU_WITH_IO--;
					}
					Q_Pos[i].CPU_BURST--;
				}
			}
		}

	LOP++;

	}
	return 0;
}

/*====================================================================================================*/
/*====================================================================================================*/
/*====================================================================================================*/


// This is the sorting algorithm for SJFSort
void SJFSort(PROCESS Proc[], int Total)
{
    int i, j;

    for(i=0; i < Total; i++)
    {
        for(j=0; j < Total-1; j++)
        {

            if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST >= 1))
			{
				if((Proc[j].CPU_BURST/2) > (Proc[j+1].CPU_BURST/2))
				{
					PROCESS tmp = Proc[j];
					Proc[j] = Proc[j+1];
					Proc[j+1] = tmp;
				}
			}
			else if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST == 0))
			{
				if((Proc[j].CPU_BURST/2) > Proc[j+1].CPU_BURST)
				{
					PROCESS tmp = Proc[j];
					Proc[j] = Proc[j+1];
					Proc[j+1] = tmp;
				}
			}
			else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST >= 1))
			{
				if(Proc[j].CPU_BURST > (Proc[j+1].CPU_BURST/2))
				{
					PROCESS tmp = Proc[j];
					Proc[j] = Proc[j+1];
					Proc[j+1] = tmp;
				}
			}
			else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST == 0))
			{
				if(Proc[j].CPU_BURST > Proc[j+1].CPU_BURST)
				{
					PROCESS tmp = Proc[j];
					Proc[j] = Proc[j+1];
					Proc[j+1] = tmp;
				}
			}
        }
    }
}
