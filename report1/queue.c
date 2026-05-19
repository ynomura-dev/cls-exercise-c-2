#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "error.h"


QUEUE_TYPE g_queue[QUEUE_SIZE + 1];

int g_queue_front = 0;
int g_queue_rear = 0;

void initQueue(void){   //fixed :)
    g_queue_front = 0;
    g_queue_rear = 0;
}

int isQueueEmpty(void){
    return g_queue_front == g_queue_rear;
}

int isQueueFull(void){
    return (g_queue_rear + 1) % QUEUE_SIZE == g_queue_front;
}

int nextIdx(int n){
    return (n + 1) % QUEUE_SIZE;
}

void enqueue(QUEUE_TYPE x){
    if (isQueueFull()) {
        raiseError("error: enqueue(): Queue is full");
    }
    g_queue[g_queue_rear] = x;
    g_queue_rear = nextIdx(g_queue_rear);
}

QUEUE_TYPE dequeue(void){
    if (isQueueEmpty()) {
        raiseError("error: dequeue(): Queue is empty");
    }
    QUEUE_TYPE temp = g_queue[g_queue_front];
    g_queue_front = nextIdx(g_queue_front);
    return temp;
}

void printQueue(void){
    for (int i=g_queue_front; i!=g_queue_rear; i=nextIdx(i)){
        printf("%s ", g_queue[i]);
    }
    printf("\n");
}