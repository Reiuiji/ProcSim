#include "ProcUtil.h"

void SJFSort(PROCESS Proc[], SIMULATION *Sim);
int SJF(PROCESS Proc[], SIMULATION *Sim);
//void IO_SJF(PROCESS Proc[], SIMULATION *Sim);

int SJF(PROCESS Proc[], SIMULATION *Sim)
{
    bool DEBUG = true;
    printf("/***********  Shortest-Job-First Algorithm ***********/\n");
    Sim->Schedule = "SJF";
    SJFSort(Proc, Sim);
//    printf("[+DEBUG+]\n");
    //ListProcess(Proc, Sim);
//    printf("[-DEBUG-]\n");

    //setup ready current and IO current
    int current = Proc[0].P_ID;
    Sim->CPU_Current = current;//set at the first Process in the ready Que
    Sim->IO_Current = -1;//there is none
    if(DEBUG == true)
    {
        ListProcess(Proc, Sim);
        ListSim(Sim);
    }
    //SnapShot(Proc, Sim);


    int i;
    for(i = 0; i<6; i++)
    {
        //IO_SJF(Proc, Sim);
        RunCPU(Proc, Sim);
        RunIO(Proc, Sim);
        Sim->Time++;
        if(DEBUG == true)
        {
            ListProcess(Proc, Sim);
            ListSim(Sim);
        }
        //SnapShot(Proc, Sim);
        SJFSort(Proc, Sim);

    }

    return 0;
}


void SJFSort(PROCESS Proc[], SIMULATION *Sim)
{
    int i, j, Total = Sim->TotalProc;

    for(i=0; i < Total; i++)
    {
        for(j=0; j < Total-1; j++)
        {

            if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST >= 1))
            {
                if((Proc[j].CPU_BURST/2) > (Proc[j+1].CPU_BURST/2))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
            else if((Proc[j].IO_BURST >= 1) && (Proc[j+1].IO_BURST == 0))
            {
                if((Proc[j].CPU_BURST/2) > Proc[j+1].CPU_BURST)
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
            else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST >= 1))
            {
                if(Proc[j].CPU_BURST > (Proc[j+1].CPU_BURST/2))
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
            else if((Proc[j].IO_BURST == 0) && (Proc[j+1].IO_BURST == 0))
            {
                if(Proc[j].CPU_BURST > Proc[j+1].CPU_BURST)
                {
                    PROCESS tmp = Proc[j];
                    Proc[j] = Proc[j+1];
                    Proc[j+1] = tmp;
                }
            }
        }
    }
}

//return the PID with the shortest job in the Device Queue
//void IO_SJF(PROCESS Proc[], SIMULATION *Sim)
//{
//    int pos, Current, Total = Sim->TotalProc;
//
//    if((Sim->IO_Current == -1) || (Proc[IOPIDtoPOS(Proc, Sim)].DeviceQueue == false))
//    {
//        Sim->IO_Current = NextIO(Proc, Sim);
//    }
//    Current = IOPIDtoPOS(Proc, Sim);
//
//    for(pos=0; pos < Total; pos++)
//    {
//        if((Proc[pos].DeviceQueue == true))
//        {
//            if((Proc[Sim->IO_Current].IO_BURST-Proc[Sim->IO_Current].IO_Duration) > (Proc[pos].IO_BURST-Proc[pos].IO_Duration))
//            {
//                Sim->IO_Current = Proc[pos].P_ID;
//            }
//        }
//
//    }
//
//}

