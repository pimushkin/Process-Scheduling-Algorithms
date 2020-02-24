#include "algorithms.h"

int main()
{
    while (1)
    {
        int algorithm;
        printf("Choose scheduling algorithm:\n"
               "\t1. First-Come, First-Served\n"
               "\t2. Shortest-Job-First\n"
               "\t3. Priority\n"
               "\t4. Round Robin\n"
               "\t5. Exit\n");
        scanf("%d", &algorithm);
        switch (algorithm)
        {
            case 1:
                FCFS();
                break;
            case 2:
                SJF();
                break;
            case 3:
                priority();
                break;
            case 4:
                roundRobin();
                break;
            case 5:
                return 0;
            default:
                printf("Incorrect input!\n");
                break;
        }
    }
}