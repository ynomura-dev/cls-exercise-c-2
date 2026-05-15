#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "error.h"


QUEUE_TYPE queue[QUEUE_SIZE];

int queue_front = 0;
int queue_rear = 0;

void initQueue(void){
    queue_front = 0;
    queue_rear = 0;     //declare even 2 times. Can I fix this?
}

int isQueueEmpty(void){
    return queue_front % QUEUE_SIZE == queue_rear;
}

int isQueueFull(void){
    return (queue_rear + 1) % QUEUE_SIZE == queue_front;
}

int next(int i){
    return (i + 1) % QUEUE_SIZE;
}

void enqueue(QUEUE_TYPE x){
    if (isQueueFull()) {
        fprintf(stderr, "error: enqueue(): Queue is full\n");
        exit(1);
    }
    queue[queue_rear] = x;
    queue_rear = next(queue_rear);
}

QUEUE_TYPE dequeue(void){
    if (isQueueEmpty()) {
        errorExit("error: dequeue(): Queue is empty");
    }
    QUEUE_TYPE temp = queue[queue_front];  // get the value first
    queue_front = next(queue_front);       // then advance the front
    return temp;
}

void printQueue(void){
    for (int i=queue_front; i!=queue_rear; i=next(i)){
        printf("%s ", queue[i]);
    }
}