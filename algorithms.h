#ifndef SCHEDULING_ALGORITHMS_H
#define SCHEDULING_ALGORITHMS_H
#include <stdio.h>
#include <malloc.h>
void FCFS();
void SJF();
void priority();
void roundRobin();
int wait, turn, countOfProcesses, totalBurst, totalTurnTime, *burst;
#endif //SCHEDULING_ALGORITHMS_H
