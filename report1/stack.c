#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "error.h"


STACK_TYPE gStack[STACK_SIZE];
int gSNum = 0;


void initStack(void){
    gSNum = 0;
}

int isStackEmpty(void){
    return gSNum == 0;
}

int isStackFull(void){
    return gSNum == STACK_SIZE;
}

void push(STACK_TYPE x){
    if (isStackFull()){
        errorExit("error: push(): Stack is full\n");
    }
    gStack[gSNum++] = x;
}

STACK_TYPE pop(void){
    if (isStackEmpty()){
        errorExit("error: pop(): Stack is empty\n");
    }
    return gStack[--gSNum];
}

STACK_TYPE peek(void){
    if (isStackEmpty()){
        errorExit("error: peek(): stack is empty\n");
    }
    return gStack[gSNum - 1];
}

void printStack(void){
    for (int i=0; i<gSNum; i++){
        printf("%s ", gStack[i]);
    }
    printf("\n");
}


