	ready_queue_amount = NUM_PROCESSES;
	while((ready_queue_amount != 0) || (io_queue_amount != 0) || (cpu_queue != NULL))
	{
		timer_increase();
		cpu_check();
		io_check();
		cpu_print();
		io_print();
	}
	
	
	timer_increase
	{
		Doesn't happen when loading for the first time in the program.
		it basically goes t=0, does these processes, then starts the timer and loops until done.
	}

**** Reorganize and remove every CPU 0 and IO 0 before moving from ready to CPU.
**** Make it so that if a process doesn't have a half burst, it reads as a -1.

cpu_check_1
{
	if(CPU_FLAG == 1)
	{
		if(Process[CPU_QUEUE].CPU_WITH_IO == 0)
		{
			IO_QUEUE[IO_QUEUE_LENGTH+1] = CPU_QUEUE;
			IO_QUEUE_LENGTH++;
			CPU_QUEUE = NULL;
			CPU_FLAG = 0;
		}
		else if(Process[CPU_QUEUE].CPU_BURST == 0)
		{
			CPU_QUEUE = NULL;
			CPU_FLAG = 0;
		}
	}
}
		
io_check_1
{
	for(i=0; i=IO_QUEUE_LENGTH; i++)
	{
		if((Process[IO_QUEUE[i]].IO_BURST == 0) && (Process[IO_Queue[i]].CPU_BURST >= 1))
		{
			CPU_QUEUE[CPU_QUEUE_LENGTH+1] = IO_QUEUE[i];
			CPU_QUEUE_LENGTH++;
			for(j=i; j<ready_queue_amount; j++)
			{
				ready_queue[j] = ready_queue[j+1];
				ready_queue[j+1] = NULL;
			}
		}
		if((Process[IO_QUEUE[i]].IO_BURST == 0) && (Process[IO_Queue[i]].CPU_BURST == 0))
		{
			for(j=i; j<ready_queue_amount; j++)
			{
				ready_queue[j] = ready_queue[j+1];
				ready_queue[j+1] = NULL;
			}
		}
	}
}

REORGANIZES EVERYTHING

cpu_check_2
{			
	if(CPU_FLAG == 0)
	{
		if((Process[READY_QUEUE[0]].CPU_BURST == 0) && (Process[READY_QUEUE[0]].IO_BURST >= 1)) // I know this is wrong, but it's something to this effect.
		{
			IO_QUEUE[IO_QUEUE_LENGTH+1] = READY_QUEUE[0] // I know this is wrong but it's something to this effect.
			for(i=0; i<ready_queue_amount; i++)
			{
				ready_queue[i] = ready_queue[i+1];
				ready_queue[i+1] = NULL;
			}
		}
		else if((Process[Ready_queue[0]].CPU_WITH_IO > 0) || Process[Ready_queue[0]].CPU_BURST > 0)
		{
			READY_QUEUE[0] = CPU_QUEUE;
			CPU_FLAG = 1;
			for(i=0; i<ready_queue_amount; i++)
			{
				ready_queue[i] = ready_queue[i+1];
				ready_queue[i+1] = NULL;
			}
		}
	}
}

CPU QUEUE PRINT
READY QUEUE PRINT
IO QUEUE PRINT
	
TIMER INCREASE