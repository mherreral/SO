#include <stdbool.h>

// Function declaration
extern void fcfs_disk(int head, int requests[]);
extern void sstf(int head, int requests[]);
extern void scan(int head, int requests[], size_t reqSize, bool Rmovement);
extern void cscan(int head, int requests[], size_t reqSize, bool Rmovement);
