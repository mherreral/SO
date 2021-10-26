#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#define MAX_CUSTOM 10

// We need to produce clients in order to the barber to take them (consume them)
void *producer(void *); //customer
void *consumer(void *); //barber

//semaphores
sem_t empty, full;

//possible hairstyles and its time
int hairstyles[4] = {500, 1000, 2000, 3000};
int chairs, freeChairs;

// struct for customer attributes
typedef struct
{
    //Thread id
    int tid;
    //Selected hairstyle
    int hairstyle;
    // How long does it takes to do that hairstyle
    int cutTime;
} clientStruct;

clientStruct customers[MAX_CUSTOM];
pthread_t ID[2];

int in = 0;
int out = 0;
int nextProduced = 0;

int main()
{
    pthread_t TID[MAX_CUSTOM];

    //read number of chairs from console
    printf("How many chairs does the barbershop has?\n");
    scanf("%d", &chairs);
    //chairs = 10;
    freeChairs = chairs;

    if (chairs >= 1)
    {

        //Initialize the emptyspots
        sem_init(&empty, 0, chairs);
        //Initialize the fullspots
        sem_init(&full, 0, 0);

        //Create the producer (clients)
        pthread_create(&TID[0], NULL, producer, (void *)&ID[0]);

        //Create the consumer (barber)
        pthread_create(&TID[1], NULL, consumer, (void *)&ID[1]);

        //Wait for threads to end
        for (int i = 0; i < 2; i++)
        {
            pthread_join(TID[i], NULL);
        }
    }

    else
    {
        printf("Can't sit any client, exiting...");
        exit(0);
    }

    return 0;
}

/*
	Producer task

*/
void *producer(void *args)
{
    while (1)
    {
        //Wait for emptyspots
        sem_wait(&empty);

        //Generate ID for each customer
        nextProduced++;

        customers[in].tid = nextProduced;
        freeChairs--;

        int sel_hair;
        sel_hair = rand() % 4;
        customers[in].hairstyle = sel_hair;
        customers[in].cutTime = hairstyles[sel_hair];

        // Print client preferences
        printf("Client number %d arrived!, selected hairstyle: %d, cuttime: %d free chairs: %d\n", customers[in].tid,
               (customers[in].hairstyle) + 1, customers[in].cutTime, freeChairs);

        //Release fullspots
        sem_post(&full);
        in = (in + 1) % MAX_CUSTOM;

        // stay in waiting room
        int time = (rand() % 4);
        sleep(time);
    }
}

/*
    Consumer task
 
*/

void *consumer(void *args)
{
    static int nextConsumed = 0;

    while (1)
    {
        //Wait for fullspots
        sem_wait(&full);
        nextConsumed = customers[out].tid;

        freeChairs++;
        printf("Barber picked customer number %d with hairstyle %d for %d, free chairs %d\n", customers[out].tid,
               (customers[out].hairstyle) + 1, customers[out].cutTime, freeChairs);

        //Do the haircut
        int time = (hairstyles[customers[out].hairstyle]) / 1000;
        sleep(time);

        printf("Ended with customer %d, the time the hairstyle took was %d ms\n", customers[out].tid,
               hairstyles[customers[out].hairstyle]);
        //Release the emptyspots
        sem_post(&empty);

        out = (out + 1) % MAX_CUSTOM;
    }
}
