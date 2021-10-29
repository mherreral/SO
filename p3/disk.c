#include <stdio.h>
#include <stdlib.h>
// This program prints the string with te movements and the quantity
int sum = 0;

void fcfs(int head, int requests[])
{
    printf("FIRST COME, FIRST SERVED ALGORITHM\n");
    printf("Sequence is: \n");
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

void scan(int head, int requests[]) {}
void cscan(int head, int requests[]) {}
int main()
{
    int requests[8] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    //fcfs(head, requests);
    sstf(head, requests);
}