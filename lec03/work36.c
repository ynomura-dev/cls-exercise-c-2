#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int STACK_TYPE;

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
        printf("%d ", gStack[i]);
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

int isGreaterThanPeek(STACK_TYPE x){
    return x > peek();
}

int isOperator(char* s){
    return strcmp(s, "+") == 0 || strcmp(s, "-") == 0 || strcmp(s, "*") == 0 || strcmp(s, "/") == 0;
    }

int calc(int a, int b, char *op){
    if (strcmp(op, "+") == 0) return b + a;
    if (strcmp(op, "-") == 0) return b - a;
    if (strcmp(op, "*") == 0) return b * a;
    if (strcmp(op, "/") == 0) return b / a;


    fprintf(stderr, "未知の演算子です: %s\n", op);
    exit(1);
}

int isStackSingle(void){
    return gSNum == 1;
}



int main(int argc, char *argv[]){
    int i;

    for (i = 1; i < argc; i++){
        if (isOperator(argv[i])){
            if (argc < 3){
                fprintf(stderr, "エラー:プログラム引数がありません\n");
                exit(1);
            }

            int a = pop();
            int b = pop();

            int r = calc(a, b, argv[i]);
            push(r);
        } 
        else {
            push(atoi(argv[i]));
        }

        printStack();
    }

    // 最後に 1 個だけ残っているはず
    if (!isStackSingle()){
        fprintf(stderr, "エラー: 数式が間違っています\n");
        exit(1);
    }

    printf("結果: %d\n", pop());
    return 0;
}






