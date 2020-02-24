#include "algorithms.h"

void priority()
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

    int priority[countOfProcesses];
    printf("Enter the priority(1 to %d): ", countOfProcesses);
    for (int i = 0; i < countOfProcesses; i++)
    {
        scanf("%d", &priority[i]);
    }

    int minimum = priority[0];
    for (int j = 1; j < countOfProcesses; j++)
    {
        if (minimum > priority[j])
        {
            minimum = priority[j];
        }
    }

    int maximum = priority[0];
    for (int j = 1; j < countOfProcesses; j++)
    {
        if (maximum < priority[j])
        {
            maximum = priority[j];
        }
    }

    printf("Process ID\t\tBurst time\t\tWait time\t\tTurnaround time\n");
    for (int n = minimum; n <= maximum; n++)
    {
        for (int i = 0; i < countOfProcesses; i++)
        {
            if (priority[i] == n)
            {
                wait = turn;
                turn = wait + burst[i];
                totalTurnTime += turn;
                printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, burst[i], wait, turn);
            }
        }
    }

    double avgWaitTime = (totalTurnTime - totalBurst) / (double)countOfProcesses;
    double avgTurnTime = (double)totalTurnTime / (double)countOfProcesses;
    printf("Average wait time\t: %lf\n", avgWaitTime);
    printf("Average turnaround time\t: %lf\n", avgTurnTime);
    printf("\n");

    free(burst);
}