#include "algorithms.h"

void roundRobin()
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

    int quantum;
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    int lowBurst = countOfProcesses; // количество раз
    printf("Process ID\tBurst time\tWait time\tTurnaround time\n");
    while (lowBurst != 0)
    {
        for (int i = 0; i < countOfProcesses; i++)
        {
            if (burst[i] <= quantum && burst[i] != 0)
            {
                wait = turn;
                turn = wait + burst[i];
                totalTurnTime += turn;
                printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, burst[i], wait, turn);
                burst[i] = 0;
                lowBurst--;
            }
            else if (burst[i] > quantum)
            {
                wait = turn;
                turn += quantum;
                printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, quantum, wait, turn);
                burst[i] -= quantum;
            }
        }
    }

    double avgWaitTime = (double)(totalTurnTime - totalBurst) / (double)countOfProcesses;
    double avgTurnTime = (double)totalTurnTime / (double)countOfProcesses;
    printf("Average wait time\t: %lf\n", avgWaitTime);
    printf("Average turnaround time\t: %lf\n", avgTurnTime);
    printf("\n");

    free(burst);
}