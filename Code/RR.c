#include "ProcUtil.h"

void RoundRobin(PROCESS Proc[], SIMULATION *Sim, int TimeQuantum);
int RR(PROCESS Proc[], SIMULATION *Sim);

int RR(PROCESS Proc[], SIMULATION *Sim)
{
    printf("/***********  Round-Robin Algorithm (time quantum 3)  ***********/\n");

    Sim->Schedule = "RR";

    RoundRobin(Proc,Sim, 3);
}


//return the CPU it needs to work with
void RoundRobin(PROCESS Proc[], SIMULATION *Sim, int TimeQuantum)
{
    int i,pos = Sim->CPU_Current;
    if(Sim->CPU_Current == -1)
    {
        Sim->CPU_Current = Proc[0].P_ID;
    }

while(IsProcComplete(Proc, Sim))
{
    if((Sim->TimeQ < TimeQuantum) && (Proc[pos].ReadyQueue == true))
    {
        Proc[pos].CPU_Duration++;

            if(Proc[pos].IO_BURST > 0)//there is IO Burst so half
            {
//                if(Proc[pos].CPU_BURST == Proc[pos].CPU_Duration)
//                int half = Proc[pos].CPU_BURST/2;
//                if(Proc[pos].CPU_BURST )
                }
        Sim->TimeQ++;
        break;
    }

    if(Proc[pos].ReadyQueue == true)
    {
        for(i=0; i<Sim->TotalProc; i++)
        {
            pos = (Sim->CPU_Current + i)%(Sim->TotalProc);
        }
        Sim->TimeQ = 0;
    }
}

}
