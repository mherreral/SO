#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// This program prints the string with te movements and the quantity


void fcfs(int head, int requests[])
{
    printf("FIRST COME, FIRST SERVED ALGORITHM\n");
    printf("Sequence is: \n");
    int sum = 0;
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", requests[i]);
        if (i == 0)
        {
            sum += (abs(head - requests[i]));
        }
        else
        {
            sum += (abs(requests[i - 1] - requests[i]));
        }
    }
    printf("\nTotal movements %d\n", sum);
}


void sstf(int head, int requests[])
{
    printf("SHORTEST SEEK TIME FIRST\n");
    printf("Sequence is: \n");

    int count;
    int sum = 0;
    while (count != 8)
    {
        int min = 1000, d, index;
        for (int i = 0; i < 8; i++)
        {
            d = abs(requests[i] - head);
            if (min > d)
            {
                min = d;
                index = i;
            }
        }
        sum += min;
        head = requests[index];
        printf("%d ", head);
        requests[index] = 10000;
        count++;
    }
    printf("\nTotal movements %d\n", sum);
}


int cmpfunc (const void * a, const void * b) {
  return ( *(int*)a - *(int*)b );
}


void scan(int head, int requests[], size_t reqSize, bool Rmovement)
{
  printf("SCAN\n");
  printf("Sequence is: \n");

  int diskSize = 200;
  int i = 0;
  int sum = 0;

  // Sort requests
  qsort(requests, reqSize, sizeof(int), cmpfunc);

  // Place iterator in head position
  int index;
  for(i = 0; i < reqSize; i++)
    {
      if(head <= requests[i])
        {
          index = i;
          break;
        }
    }

  // Movement right or left
  if(Rmovement) // Right
    {
      for(i = index; i < reqSize; i++)
        {
          printf("%d ", head);
          sum += abs(head - requests[i]);
          head = requests[i];
        }

      //  Move to max disk size
      sum += abs(diskSize-1 - requests[i-1]);
      head = diskSize-1;

      for(i = index-1; i >= 0; i--)
        {
          printf("%d ", head);
          sum += abs(head - requests[i]);
          head = requests[i];
        }
    }
  else // Left
    {
      for(i = index-1; i >= 0; i--)
        {
          printf("%d ", head);
          sum += abs(head - requests[i]);
          head = requests[i];
        }

      //  Move to mix disk size
      sum += abs(requests[i+1]);

      head = 0;
      for(i = index; i < reqSize; i++)
        {
          printf("%d ", head);
          sum += abs(head - requests[i]);
          head = requests[i];
        }
    }
  printf("\nTotal movements: %d\n", sum);
}


void cscan(int head, int requests[], size_t reqSize, bool Rmovement)
{
  printf("C-SCAN\n");
  printf("Sequence is: \n");

  int diskSize = 200;
  int i = 0;
  int sum = 0;
  
  // Sort requests
  qsort(requests, reqSize, sizeof(int), cmpfunc);

  // Place iterator in head position
  int index;
  for(i = 0; i < reqSize; i++)
    {
      if(head <= requests[i])
        {
          index = i;
          break;
        }
    }

  // Movement right or left
  if(Rmovement) // Right
    {
      for(i = index; i < reqSize; i++)
        {
          printf("%d ", head);
          sum += abs(head - requests[i]);
          head = requests[i];
        }

      //  Move to max disk size
      sum += abs(diskSize-1 - requests[i-1]);
      printf("%d ", 199);

      // Move from max to min disk size
      sum += abs(diskSize-1);
      head = 0;
      for(i = 0; i < index; i++)
        {
          printf("%d ", head);
          sum += abs(head - requests[i]);
          head = requests[i];
        }
    }
  else // Left
    {
      for(i = index-1; i >= 0; i--)
        {
          printf("%d ", head);
          sum += abs(head - requests[i]);
          head = requests[i];
        }

      // Move to min disk size 
      sum += abs(requests[i+1]);
      printf("%d ", 0);

      // Move from max to min disk size
      sum += abs(diskSize-1);
      head = diskSize-1;
      for(i = reqSize-1; i >= index; i--)
        {
          printf("%d ", head);
          sum += abs(head - requests[i]);
          head = requests[i];
        }
    }
  printf("\nTotal movements: %d\n", sum);
}


int main()
{
    const int REQUESTS_SIZE = 10;

    int requests[] = {30, 35, 98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;

    // fcfs(head, requests);
    // sstf(head, requests);
    // cscan(head, requests, REQUESTS_SIZE, false);
    // scan(head, requests, REQUESTS_SIZE, true);
}
