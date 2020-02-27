#ifndef SCHEDULING_ALGORITHMS_H
#define SCHEDULING_ALGORITHMS_H
#include <stdio.h>
#include <malloc.h>
void FCFS();
void SJF();
void priority();
void roundRobin();
typedef struct Process
{
    int id, burst, wait, turn;
} Process;
int countOfProcesses, totalBurst, totalTurnTime;
#endif //SCHEDULING_ALGORITHMS_H