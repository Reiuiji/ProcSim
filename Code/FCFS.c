//Get arrival and service times for each process from queue.

//Get total time for each process and store in an array
//Then sort the processes based on arrival time. Use service time to set time intervals.

//Send back to process scheduler in proper order. 
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include"ProcUtil.h"
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )
PROCESS Proc[]         //proc must be global
char queue[]       //queue variable should be global
void FCFS(Proc[])  //Function to sort by arrival time


int FCFS(Proc[])  //Function to sort by arrival time{

for(int i=0;i=sizeof(Proc)-1;i++){
queue[i]=Proc[i];
return queue;
}
void main(){
    FCFS(Proc[]);
}

/*char arrival(queue)      //Function to get arrival time

void main(){
  arrival(file);
  FCFS(Proc[]);
}

FCFS(Proc[]){      
  int s=ARRAY_SIZE(Proc);
  for(int j=0; j=s-1;j++){    //Sorting by process ID, not arrival time
   for(int i=0; i=s-1;i++){   
      if(Proc[i]>Proc[i+1]){
        int temp=Proc[i];
        Proc[i]=Proc[i+1];
        Proc[i+1]=temp;
        }
      }
  
    }
}


  
  arrival(char queue1[]){
    
  
    //Somehow count characters to read in arrival times from file
    File *file;
    file=fopen("queue.c", r);
    //somehow read in arrival times
    
    return file;
  }
*/




  
