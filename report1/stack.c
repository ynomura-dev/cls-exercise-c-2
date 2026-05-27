#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "error.h"


STACK_TYPE g_stack[STACK_SIZE];
int g_stack_num = 0;


void init_stack(void){
    g_stack_num = 0;
}

int is_stack_empty(void){
    return g_stack_num == 0;
}

int is_stack_full(void){
    return g_stack_num == STACK_SIZE;
}

void push(STACK_TYPE x){
    if (is_stack_full()){
        raise_error("error: push(): Stack is full");
    }
    g_stack[g_stack_num++] = x;
}

STACK_TYPE pop(void){
    if (is_stack_empty()){
        raise_error("error: pop(): Stack is empty");
    }
    return g_stack[--g_stack_num];
}

STACK_TYPE peek(void){
    if (is_stack_empty()){
        raise_error("error: peek(): Stack is empty");
    }
    return g_stack[g_stack_num - 1];
}

void print_stack(void){
    for (int i=0; i<g_stack_num; i++){
        printf("%s ", g_stack[i]);
    }
    printf("\n");
}


