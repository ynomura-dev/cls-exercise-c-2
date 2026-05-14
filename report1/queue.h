#include <stdio.h>
#include <stdlib.h>


typedef int QUEUE_TYPE;
#define QUEUE_SIZE 1000

void errorExit(const char *message);

void printQueue(int tabs);
int isQueueEmpty(void);
int isQueueFull(void);
void enqueue(QUEUE_TYPE x);
QUEUE_TYPE dequeue(void);
void initQueue(void);
QUEUE_TYPE dequeue(void);
void initQueue(void);