/*
 * SJF
 * Shortest Job First
 * non-preemptive
 */

Info:
Process with the shortest CPU_burst time will go first
non-preemtive so there will be no interupts

input parameters:
P_ID      | the process ID
CPU_Burst | The amount of time for the process to use the cpu 
I/O_Burst | The amount of time for I/O operations, executes exactly half way through the CPU_Burst

Data: Initialize
ready_queue    | queue to house the process for the cpu 
device queue   | queue to house the I/O operations
complete queue | queue to house completed processes
time           | time clock for the schedule

process structure
*P_ID
*CPU_Burst
*I/O Burst

Pseudo:

Grabs the input data

parse the input data 
> process.P_ID 
> process.CPU_Burst 
> process.I/O Burst

stores each process in the ready_queue based on which one was inputed first
> ready_queue

shorts the ready_queue with the shortest CPU_Burst goes first

while there are processes in the ready_queue
	run the process

	while current process time remaining is greater than zero
		if(time = (1/2)*process.CPU_Burst)
			store the process.I/O_Burst in the device queue
		endif
	        decrement process time remaining
	endwhile
endwhile
