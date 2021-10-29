#include <stdio.h>
#include <stdlib.h>
#include "main.h"
int category;

int main()
{
    // Select category
    printf("Which category are you interested in? (give the number associated)\n");
    printf("1: Process\n");
    printf("2: Disk scheduling\n");
    scanf("%d", &category);

    //Check if its a correct category or not
    if (category != 1 || category != 2)
    {
        printf("You entered an invalid category, exiting...\n");
        exit(0);
    }

    // In case user wants to exec process scheduling
    if (category == 1)
    {
        int nproc = 0;
        char *process;
        printf("Enter the number of process in the queue\n");
        scanf("%i", &nproc);
        if (nproc > 10)
        {
            printf("Exceed max number");
            exit(0);
        }
        ProcessStruct processes[nproc];

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

        char *algorithm;
        printf("Type all for running all algorithms or the name of the algorithm you want to run\n");
        printf("The posible algorithms names are: fcfs, sjf, p, rr\n");
        scanf("%c", &algorithm);
        //TODO CALL THE FILE
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
}