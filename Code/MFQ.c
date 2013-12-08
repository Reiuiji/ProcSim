//Get all 3 queues
//Get arrival times
//Get Burst Times
//Measure Process Aging
//Plan intervals to transfer processes

#include <stdio.h>
struct queue1;
struct queue2;
struct queue3;
int quantum;

void MFQ(){

/*Getting burst times from ReadyQueue
Get divide into three queues as a result
Place processes with burst time>3 on queue 1
Place processes with burst times between 3 and 8 on queue 2
Place processes with burst times greater than 8 on queue3
Use RR to sort queue 1 and 2. 
Use FCFS to sort queue3
Place sorted queues on IO queue(concatenate) in order */





}
