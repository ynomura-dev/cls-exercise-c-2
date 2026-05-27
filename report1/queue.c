#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "error.h"


QUEUE_TYPE g_queue[QUEUE_SIZE + 1];

int g_queue_front = 0;
int g_queue_rear = 0;

void init_queue(void){   //fixed :)
    g_queue_front = 0;
    g_queue_rear = 0;
}

int is_queue_empty(void){
    return g_queue_front == g_queue_rear;
}

int is_queue_full(void){
    return (g_queue_rear + 1) % QUEUE_SIZE == g_queue_front;
}

int next_idx(int i){
    return (i + 1) % QUEUE_SIZE;
}

void enqueue(QUEUE_TYPE x){
    if (is_queue_full()) {
        raise_error("error: enqueue(): Queue is full");
    }
    g_queue[g_queue_rear] = x;
    g_queue_rear = next_idx(g_queue_rear);
}

QUEUE_TYPE dequeue(void){
    if (is_queue_empty()) {
        raise_error("error: dequeue(): Queue is empty");
    }
    QUEUE_TYPE temp = g_queue[g_queue_front];
    g_queue_front = next_idx(g_queue_front);
    return temp;
}

void print_queue(void){
    for (int i=g_queue_front; i!=g_queue_rear; i=next_idx(i)){
        printf("%s ", g_queue[i]);
    }
    printf("\n");
}