#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "error.h"



QUEUE_TYPE queue[QUEUE_SIZE];
int queue_rear = -1;

void printQueue(int tabs){
    int i, j;
    for (j = 0; j < tabs; j++){
        printf("\t");
    }
    printf("QUEUE[ ");
    for (i = 0; i <= queue_rear; i++){
        printf("%d ", queue[i]);
    }
    printf("]\n");
}

int isQueueEmpty(void){
    return queue_rear == -1;
}

int isQueueFull(void){
    return queue_rear == QUEUE_SIZE - 1;
}

void enqueue(QUEUE_TYPE x){
    if (isQueueFull()) {
        errorExit("エラー: キューがフル状態でenqueueはできません");
    }
    queue[++queue_rear] = x;
}

QUEUE_TYPE dequeue(void){
    QUEUE_TYPE temp = queue[0];
    if (isQueueEmpty()) {
        errorExit("エラー: キューが空状態でdequeueはできません");
    }
    for (int i = 0; i < queue_rear; i++) {
        queue[i] = queue[i + 1];
    }
    queue_rear--;
    return temp;
}


void initQueue(void){
    queue_rear = -1;
}