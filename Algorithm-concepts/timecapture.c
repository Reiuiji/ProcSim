/*
 * time capture
 * Round Robin Scheduling
 * preemptive
 */

Info:
This will describe the method of captureing the time for the cpu simulation

if( cpu simulation time equals the capture time period )

	prints out the following

	t = ${time}
	CPU loading job ${first on ready queue} : PCU burst (${process burst time}) IO burst (${process IO burst time}) \nextline
	current state of ready queue: ${display the first ten process in the queue} \nextline
	current state of device queue: ${display the first ten in IO queue} \nextline


endif


