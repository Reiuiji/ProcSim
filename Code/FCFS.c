//Get arrival and service times for each process from queue.

//Get total time for each process and store in an array
//Then sort the processes based on arrival time. Use service time to set time intervals.

//Send back to process scheduler in proper order.
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )
int n[];         //n must be global
char queue[];       //queue variable should be global
void FCFS(n[]);  //Function to sort by arrival time
char arrival(queue);      //Function to get arrival time

void main(){
  arrival(file);
  FCFS(n[])
}

FCFS(int n[]){
  int s=ARRAY_SIZE(n);
  for(int j=0; j=s-1;j++){    //Sorting by arrival time
   for(int i=0; i=s-1;i++){
      if(n[i]>n[i+1]){
        int temp=n[i];
        n[i]=n[i+1];
        n[i+1]=temp;
        }
      }

  }

  arrival(char queue[]){
    //Somehow count characters to read in arrival times from file
    File *file;
    file=fopen("queue.c", r);
    //somehow read in arrival times
    return n[];
  }



