#include "ProcUtil.h"

void SJFSort(PROCESS Proc[], int Total);

void SJFSort(PROCESS Proc[], int Total)
{
    int i, j;

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
