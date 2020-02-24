#include "algorithms.h"

void FCFS()
{
    wait = 0;
    turn = 0;
    totalBurst = 0;
    totalTurnTime = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &countOfProcesses);

    burst = malloc(countOfProcesses * sizeof(int));
    printf("Enter the burst time: ");
    for (int i = 0; i < countOfProcesses; i++)
    {
        scanf("%d", &burst[i]);
        totalBurst += burst[i];
    }

    printf("Process ID\tBurst time\tWait time\tTurnaround time\n");
    for (int i = 0; i < countOfProcesses; i++)
    {
        if (i == 0)
        {
            turn += burst[i];
            totalTurnTime += turn;
            printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, burst[i], wait, turn);
        }
        else
        {
            wait = turn;
            turn += burst[i];
            totalTurnTime += turn;
            printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, burst[i], wait, turn);
        }
    }

    double avgWaitTime = (double)(totalTurnTime - totalBurst) / (double)countOfProcesses;
    double avgTurnTime = (double)totalTurnTime / (double)countOfProcesses;
    printf("Average wait time\t: %lf\n", avgWaitTime);
    printf("Average turnaround time\t: %lf\n", avgTurnTime);
    printf("\n");

    free(burst);
}