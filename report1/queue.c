#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "error.h"


QUEUE_TYPE queue[QUEUE_SIZE];

int queue_front = 0;
int queue_rear = 0;


int isQueueEmpty(void){
    return queue_front % QUEUE_SIZE == queue_rear;
}

int isQueueFull(void){
    return (queue_rear + 1) % QUEUE_SIZE == queue_front;
}

void initQueue(void){   //fixed :)
    queue_front = 0;
    queue_rear = 0;
}

int nextIdx(int i){
    return (i + 1) % QUEUE_SIZE;
}

void enqueue(QUEUE_TYPE x){
    if (isQueueFull()) {
        errorExit("error: enqueue(): Queue is full");
    }
    queue[queue_rear] = x;
    queue_rear = nextIdx(queue_rear);
}

QUEUE_TYPE dequeue(void){
    if (isQueueEmpty()) {
        errorExit("error: dequeue(): Queue is empty");
    }
    QUEUE_TYPE temp = queue[queue_front];
    queue_front = nextIdx(queue_front);
    return temp;
}

void printQueue(void){
    for (int i=queue_front; i!=queue_rear; i=nextIdx(i)){
        printf("%s ", queue[i]);
    }
}