#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "error.h"



int gSNum = 0;         
STACK_TYPE gStack[STACK_SIZE];

void push(STACK_TYPE x){
    gStack[gSNum++] = x;
}

STACK_TYPE pop(void){
    return gStack[--gSNum];
}

void printStack(void){
    int i;
    printf("STACK[ ");
    for (i=0; i<gSNum; i++){
        printf("%s ", gStack[i]);
    }
    printf("]\n");
}

int isStackEmpty(void){
    return gSNum == 0;
}

int isStackFull(void){
    return gSNum == STACK_SIZE;
}

int isEnteredINIT(char* n){
    return (strcmp(n, "INIT") == 0 ? 1 : 0);
}


int initStack(void){
    gSNum = 0;
    return 0;
}

STACK_TYPE peek(void){
    if (isStackEmpty()){
        errorExit("エラー: 空状態でpeekはできません\n");
    } else {
        return gStack[gSNum - 1];
    }
}

int isStackSingle(void){
    return gSNum == 1;
}


