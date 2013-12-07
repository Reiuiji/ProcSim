//Get arrival and service times for each process from queue.

//Get total time for each process and store in an array
//Then sort the processes based on arrival time. Use service time to set time intervals.

//Send back to process scheduler in proper order.
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include"ProcUtil.h"
#define ARRAY_SIZE( array ) sizeof( array ) / sizeof( array[0] )



int FCFS(PROCESS Proc[], SIMULATION *Sim);
void FCFSSort(PROCESS Proc[], SIMULATION *Sim);
void IO_FCFS(PROCESS Proc[], SIMULATION *Sim);

int FCFS(PROCESS Proc[], SIMULATION *Sim)
{
    bool DEBUG = false;
    printf("/***********  First-Come-First-Serve Algorithm ***********/\n");
    Sim->Schedule = "FCFS";
    FCFSSort(Proc, Sim);
     //setup ready current and IO current
    int current = Proc[0].P_ID;
    Sim->CPU_Current = current;//set at the first Process in the ready Queue
    Sim->IO_Current = -1;//there is none
    if(DEBUG == true)
    {
        ListProcess(Proc, Sim);
        ListSim(Sim);
    }
    //SnapShot(Proc, Sim);


    int i;
    while(IsProcComplete(Proc, Sim))
    {
        FCFSSort(Proc, Sim);

        //IO_SJF(Proc, Sim);
        RunCPU(Proc, Sim);
        RunIO(Proc, Sim);

        Sim->Time++;
        if(DEBUG == true)
        {
            ListProcess(Proc, Sim);
            ListSim(Sim);
        }

        CheckCPU(Proc, Sim);
        CheckIO(Proc, Sim);
        //SnapShot(Proc, Sim);

    }

    return 0;
}

void FCFSSort(PROCESS Proc[], SIMULATION *Sim)
{
    int i, j, Total = Sim->TotalProc;

    for(i=0; i < Total; i++)
    {
        for(j=0; j < Total-1; j++)
        {

            if((Proc[j].P_ID>Proc[j+1].P_ID)&&(Proc[j+1].IO_BURST >= 1))
            {

                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;

            }
            else if(Proc[j].P_ID==Proc[j+1].P_ID){
            printf("Two different processes cannot have the same ID number!!! \n");
            }
        }
    }

}

/*PROCESS Proc[]         //proc must be global
int queue[]       //queue variable should be global
void FCFS(Proc[])  //Function to sort by arrival time


int FCFS(Proc[])  //Function to sort by arrival time{

for(int i=0;i=sizeof(Proc)-1;i++){
queue[i]=Proc[i];
return queue;
}
void main(){
    FCFS(Proc[]);
}

char arrival(queue)      //Function to get arrival time

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





