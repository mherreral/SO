#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/main.h"
#include "include/cpu.h"
#include "include/disk.h"

ProcessStruct *processes;
int category;
int nproc;
int q;

int main()
{
    // Select category
    printf("Which category are you interested in? (give the number associated)\n");
    printf("1: Process\n");
    printf("2: Disk scheduling\n");
    scanf("%d", &category);

    //Check if its a correct category or not
    if (category != 1 & category != 2)
    {
        printf("You entered an invalid category, exiting...\n");
        exit(0);
    }

    // In case user wants to exec process scheduling
    if (category == 1)
    {
        nproc = 0;
        char *process;
        printf("Enter the number of process in the queue\n");
        scanf("%i", &nproc);
        if (nproc > 10)
        {
            printf("Exceed max number");
            exit(0);
        }
        //ProcessStruct processes[nproc];
        processes = (int *)malloc(sizeof(int) * nproc);

        for (int i = 0; i < nproc; i++)
        {
            int aux;
            processes[i].id = i;

            printf("Burst time for %d\n", i);
            scanf("%d", &aux);
            processes[i].burstTime = aux;

            printf("Arrival time for %d\n", i);
            scanf("%d", &aux);
            processes[i].arrivalTime = aux;

            printf("Priority for %d\n", i);
            scanf("%d", &aux);
            processes[i].priority = aux;
        }

        char algorithm[4];
        printf("Type all for running all algorithms or the name of the algorithm you want to run\n");
        printf("The posible algorithms names are: fcfs, sjf, p, rr\n");
        scanf("%s", algorithm);
        if (strcmp(algorithm, "fcfs") == 0)
        {
            fcfs_cpu(processes, nproc);
        }
        else if (strcmp(algorithm, "sjf") == 0)
        {
            sjf(processes, nproc);
        }
        else if (strcmp(algorithm, "p") == 0)
        {
            priorityNP(processes, nproc);
        }
        else if (strcmp(algorithm, "rr") == 0)
        {
            q = 0;
            printf("Type the quantum (ut)\n");
            scanf("%d", &q);
            rr(processes, nproc, q);
        }
        else if (strcmp(algorithm, "all") == 0)
        {
            q = 0;
            printf("Type the quantum (ut)\n");
            scanf("%d", &q);
            fcfs_cpu(processes, nproc);
            sjf(processes, nproc);
            priorityNP(processes, nproc);
            rr(processes, nproc, q);
        }
        else
        {
            printf("Entered wrong algorithm");
            exit(0);
        }
        free(processes);
    }

    // In case user wants to exec disk scheduling
    else
    {
        int head;
        int requests[10];

        // ask for head
        printf("Where does the head starts?\n");
        scanf("%d", &head);

        // ask for requests
        printf("Type the request one by one\n");
        for (int i = 0; i < 10; i++)
        {
            scanf("%d", &requests[i]);
        }
        // TODO llamar algoritmos
    }
    return 0;
}