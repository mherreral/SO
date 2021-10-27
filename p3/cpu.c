#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int tt = 0;
int tot_tt = 0;
int wt = 0;
int tot_wt = 0;

void initialize_vars()
{
    int tt = 0;
    int wt = 0;
}

void first_process(ProcessStruct process)
{
    printf("******************\n");
    printf("Process %d\n", process.id);
    printf("Waiting time:  0\n");
    printf("Turnaround time:    %d\n", process.burstTime);
    tt = process.burstTime;
    tot_tt += tt;
}

void times(ProcessStruct process, int nproc)
{
    int id = process.id;
    int bt = process.burstTime;
    printf("******************\n");
    printf("Process:    %d\n", id);
    printf("Waiting time:  %d\n", tt);
    printf("Turnaround time:    %d\n", tt + bt);
    wt = tt;
    tot_wt += wt;
    tt += bt;
    tot_tt += tt;
}

void avg_times(int nproc)
{
    // find average
    printf("******************\n");
    float avg_tt = tot_tt / nproc;
    float avg_wt = tot_wt / nproc;
    printf("Average waiting time = %.3f, Average turnaround time = %.3f\n", avg_wt, avg_tt);
    printf("******************\n");
}

void fcfs(ProcessStruct processes[], int nproc)
{
    initialize_vars();
    printf("FIRST COME, FIRST SERVED ALGORITHM\n");
    // sort according to arrival time
    for (int i = 0; i < nproc; i++)
    {
        for (int j = i + 1; j < nproc; j++)
        {
            if (processes[i].arrivalTime > processes[j].arrivalTime)
            {
                ProcessStruct tmp = processes[i];
                processes[i] = processes[j];
                processes[j] = tmp;
            }
        }
    }

    // Waiting and turnaround time per process and average
    // Turnaround time = Burst time + Waiting time
    // Waiting time = Turnaround time - Burst time

    // Info for the first process
    first_process(processes[0]);

    // rest of processes
    for (int i = 1; i < nproc; i++)
    {
        times(processes[i], nproc);
    }

    avg_times(nproc);
    printf("\n\n\n");
}

void sjf(ProcessStruct processes[], int nproc)
{
    initialize_vars();
    printf("SHORTEST JOB FIRST ALGORITHM\n");
    // sort according to burst time
    for (int i = 0; i < nproc; i++)
    {
        for (int j = i + 1; j < nproc; j++)
        {
            if (processes[i].burstTime > processes[j].burstTime)
            {
                ProcessStruct tmp = processes[i];
                processes[i] = processes[j];
                processes[j] = tmp;
            }
        }
    }

    // Info for the first process
    first_process(processes[0]);

    // rest of processes
    for (int i = 1; i < nproc; i++)
    {
        times(processes[i], nproc);
    }

    avg_times(nproc);
    printf("\n\n\n");
}

void priorityNP(ProcessStruct processes[], int nproc)
{
    initialize_vars();
    printf("PRIORITY NON PREEMPTIVE ALGORITHM\n");
    // sort according to priority
    for (int i = 0; i < nproc; i++)
    {
        for (int j = i + 1; j < nproc; j++)
        {
            if (processes[i].priority > processes[j].priority)
            {
                ProcessStruct tmp = processes[i];
                processes[i] = processes[j];
                processes[j] = tmp;
            }
        }
    }

    // Info for the first process
    first_process(processes[0]);

    // rest of processes
    for (int i = 1; i < nproc; i++)
    {
        times(processes[i], nproc);
    }

    avg_times(nproc);
    printf("\n\n\n");
}

void rr(ProcessStruct processes[], int nproc, int q)
{
    initialize_vars();
    printf("ROUND ROBIN ALGORITHM\n");
    // sort according to priority
    for (int i = 0; i < nproc; i++)
    {
        for (int j = i + 1; j < nproc; j++)
        {
            if (processes[i].arrivalTime > processes[j].arrivalTime)
            {
                ProcessStruct tmp = processes[i];
                processes[i] = processes[j];
                processes[j] = tmp;
            }
        }
    }
    int i, total = 0, x, counter = 0;
    x = nproc;

    for (total = 0, i = 0; x != 0;)
    {
        if (processes[i].burstTime <= q && processes[i].burstTime > 0)
        {
            total = total + processes[i].burstTime;
            processes[i].burstTime = 0;
            counter = 1;
        }
        else if (processes[i].burstTime > 0)
        {
            processes[i].burstTime = processes[i].burstTime - q;
            total += q;
        }
        if (processes[i].burstTime == 0 && counter == 1)
        {
            x--;
            printf("Process:    %d\n", processes[i].id);
            printf("Wait time:  %d\n", total - processes[i].arrivalTime - processes[i].burstTime);
            printf("Turnaround time:    %d\n", total - processes[i].arrivalTime);
            wt += total - processes[i].arrivalTime - processes[i].burstTime;
            tt += total - processes[i].arrivalTime;
            counter = 0;
        }
        if (i == nproc - 1)
        {
            i = 0;
        }
        else if (processes[i + 1].arrivalTime <= total)
        {
            i++;
        }
        else
        {
            i = 0;
        }
    }
    avg_times(nproc);
    printf("\n\n\n");
}

int main()
{
    int nproc = 3;
    ProcessStruct processes[nproc];

    // proceso 0
    processes[0].id = 0;
    processes[0].arrivalTime = 0;
    processes[0].burstTime = 3;
    processes[0].priority = 0;

    // proceso 1
    processes[1].id = 1;
    processes[1].arrivalTime = 2;
    processes[1].burstTime = 2;
    processes[1].priority = 1;

    // proceso 2
    processes[2].id = 2;
    processes[2].arrivalTime = 1;
    processes[2].burstTime = 6;
    processes[2].priority = 3;

    //fcfs(processes, nproc);
    //sjf(processes, nproc);
    //priorityNP(processes, nproc);
    rr(processes, nproc, 2);
}