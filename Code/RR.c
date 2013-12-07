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

}
