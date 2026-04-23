#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef double STACK_TYPE;

#define STACK_SIZE 10

STACK_TYPE gStack[STACK_SIZE];
int gSNum = 0;         

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
        printf("%f ", gStack[i]);
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
    if (strcmp(n, "INIT") == 0){
        return 1;
    } else {
        return 0;
    }
}

int initStack(char* n){
    gSNum = 0;
    return 0;
}

STACK_TYPE peek(void){
    if (isStackEmpty()){
        fprintf(stderr, "エラー: 空状態でpeekはできません\n");
        exit(1);
    } else {
        return gStack[gSNum - 1];
    }
}

/******************************************************
* スタックの利用部分
*   - 今回はmain関数は一切修正せずに使用する
******************************************************/
int main(int argc, char *argv[]){
    int i;

    for (i=1; i<argc; i++){
        push(atof(argv[i]));
    }

    printf("peek前: ");
    printStack();

    printf("peek: %f\n", peek());

    /* peekの前と後でスタックの内容が変わっていないことを確認する */
    printf("peek後: ");
    printStack();
    return 0;
}   


