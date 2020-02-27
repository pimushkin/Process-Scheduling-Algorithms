#include "algorithms.h"

void priority()
{
    totalBurst = 0;
    totalTurnTime = 0;
    Process* process = NULL;

    printf("Enter the number of processes: ");
    scanf("%d", &countOfProcesses);

    process = malloc(countOfProcesses * sizeof(Process));

    printf("Enter the burst time: ");
    for (int i = 0; i < countOfProcesses; i++)
    {
        process[i].id = i + 1;
        scanf("%d", &process[i].burst);
        totalBurst += process[i].burst;
    }

    int* priority = malloc(countOfProcesses * sizeof(int));
    printf("Enter the priority(1 to %d): ", countOfProcesses);
    for (int i = 0; i < countOfProcesses; i++)
    {
        scanf("%d", &priority[i]);
    }

    for (int i = 1; i < countOfProcesses; ++i)
    {
        for (int j = i; j > 0 && priority[j] < priority[j - 1]; --j)
        {
            Process temp = process[j];
            process[j] = process[j - 1];
            process[j - 1] = temp;
        }
    }

    printf("Process ID\tBurst time\tWait time\tTurnaround time\n");
    process[0].wait = 0;
    for (int i = 0; i < countOfProcesses; i++)
    {
        if (i != 0)
        {
            process[i].wait = process[i - 1].turn;
        }
        process[i].turn = process[i].wait + process[i].burst;
        totalTurnTime += process[i].turn;
        printf("%d\t\t%d\t\t%d\t\t%d\n", process[i].id, process[i].burst, process[i].wait, process[i].turn);
    }

    double avgWaitTime = (totalTurnTime - totalBurst) / (double)countOfProcesses;
    double avgTurnTime = (double)totalTurnTime / (double)countOfProcesses;
    printf("Average wait time\t: %lf\n", avgWaitTime);
    printf("Average turnaround time\t: %lf\n", avgTurnTime);
    printf("\n");

    free(process);
    free(priority);
}