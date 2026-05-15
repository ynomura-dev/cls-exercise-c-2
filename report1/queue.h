#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 1000
typedef char* QUEUE_TYPE;


void printQueue(void);
int isQueueEmpty(void);
int isQueueFull(void);
void enqueue(QUEUE_TYPE x);
QUEUE_TYPE dequeue(void);
void initQueue(void);
