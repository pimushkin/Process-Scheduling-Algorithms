#include "algorithms.h"

void roundRobin()
{
    totalBurst = 0;
    totalTurnTime = 0;
    Process* process = NULL;
    
    printf("Enter the number of process: ");
    scanf("%d", &countOfProcesses);

    process = (Process*)malloc(countOfProcesses * sizeof(Process));
    
    printf("Enter the burst time: ");
    for (int i = 0; i < countOfProcesses; i++)
    {
        process[i].id = i + 1;
        scanf("%d", &process[i].burst);
        totalBurst += process[i].burst;
    }

    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("Process ID\tBurst time\tWait time\tTurnaround time\n");
    process[0].wait = 0;
    int turn = 0;
    _Bool firstProcess = 0;
    int countOfProcessesWithLowBurst = countOfProcesses;
    while (countOfProcessesWithLowBurst != 0)
    {
        for (int i = 0; i < countOfProcesses; i++)
        {
            if (process[i].burst <= quantum && process[i].burst != 0)
            {
                if (firstProcess)
                {
                    process[i].wait = turn;
                }
                firstProcess = 1;
                turn = process[i].wait + process[i].burst;
                totalTurnTime += turn;
                printf("%d\t\t%d\t\t%d\t\t%d\n", process[i].id, process[i].burst, process[i].wait, turn);
                process[i].burst = 0;
                countOfProcessesWithLowBurst--;
            }
            else if (process[i].burst > quantum)
            {
                if (firstProcess)
                {
                    process[i].wait = turn;

                }
                firstProcess = 1;
                turn += quantum;
                printf("%d\t\t%d\t\t%d\t\t%d\n", process[i].id, quantum, process[i].wait, turn);
                process[i].burst -= quantum;
            }
        }
    }

    double avgWaitTime = (double)(totalTurnTime - totalBurst) / (double)countOfProcesses;
    double avgTurnTime = (double)totalTurnTime / (double)countOfProcesses;
    printf("Average wait time\t: %lf\n", avgWaitTime);
    printf("Average turnaround time\t: %lf\n", avgTurnTime);
    printf("\n");

    free(process);
}