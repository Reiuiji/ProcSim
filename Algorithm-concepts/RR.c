/*
 * RR
 * Round Robin Scheduling
 *
 * time quantum is 3 seconds
 *
 * preemptive
 */

Info:
Process that request the CPU first is allocated first
preemtive is that there are going to be interupts

input parameters:
P_ID      | the process ID
CPU_Burst | The amount of time for the process to use the cpu 
I/O_Burst | The amount of time for I/O operations, executes exactly half way through the CPU_Burst
Priority  | The priority of the processor: lower the number = high priority

Data: Initialize
ready_queue    | queue to house the process for the cpu 
device queue   | queue to house the I/O operations
complete queue | queue to house completed processes
time           | time clock for the schedule

process structure
*P_ID
*CPU_Burst
*I/O Burst
*Priority

Pseudo:

Grabs the input data

parse the input data 
> process.P_ID 
> process.CPU_Burst 
> process.I/O Burst
> process.Priority
> process.run_time = process.CPU_Burst;

stores each process in the ready_queue based on which one was inputed first
> ready_queue

while there are processes in the ready_queue

	while time mod round robin time quantum not equal zero

		if(process.run_time = (1/2)*process.CPU_Burst)
			store the process.I/O_Burst in the device queue
		endif
	        decrement process.run_time
			if(process.run_time lessthan or equal to zero)
				delete process from the ready queue
			endif
		Increment the time
	endwhile

endwhile
