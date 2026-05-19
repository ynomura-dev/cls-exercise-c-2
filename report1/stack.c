#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "error.h"


STACK_TYPE g_stack[STACK_SIZE];
int g_stack_num = 0;


void initStack(void){
    g_stack_num = 0;
}

int isStackEmpty(void){
    return g_stack_num == 0;
}

int isStackFull(void){
    return g_stack_num == STACK_SIZE;
}

void push(STACK_TYPE x){
    if (isStackFull()){
        raiseError("error: push(): Stack is full");
    }
    g_stack[g_stack_num++] = x;
}

STACK_TYPE pop(void){
    if (isStackEmpty()){
        raiseError("error: pop(): Stack is empty");
    }
    return g_stack[--g_stack_num];
}

STACK_TYPE peek(void){
    if (isStackEmpty()){
        raiseError("error: peek(): Stack is empty");
    }
    return g_stack[g_stack_num - 1];
}

void printStack(void){
    for (int i=0; i<g_stack_num; i++){
        printf("%s ", g_stack[i]);
    }
    printf("\n");
}


