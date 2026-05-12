#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef float STACK_TYPE;

#define STACK_SIZE 100

STACK_TYPE gStack[STACK_SIZE];
int gSNum = 0;

void push(STACK_TYPE x){
    if (gSNum >= STACK_SIZE){
        fprintf(stderr, "エラー: スタックが満杯です\n");
        exit(1);
    }
    gStack[gSNum++] = x;
}

STACK_TYPE pop(void){
    if (gSNum <= 0){
        fprintf(stderr, "エラー: スタックが空です\n");
        exit(1);
    }
    return gStack[--gSNum];
}

int isOperator(char* s){
    return strcmp(s, "+") == 0 ||
           strcmp(s, "-") == 0 ||
           strcmp(s, "*") == 0 ||
           strcmp(s, "/") == 0;
}

float calc(float left, float right, char *op){
    if (strcmp(op, "+") == 0) return left + right;
    if (strcmp(op, "-") == 0) return left - right;
    if (strcmp(op, "*") == 0) return left * right;
    if (strcmp(op, "/") == 0) return left / right;

    fprintf(stderr, "未知の演算子です: %s\n", op);
    exit(1);
}

int main(int argc, char *argv[]){
    int i;

    for (i = 1; i < argc; i++){
        if (isOperator(argv[i])){
            if (gSNum < 2){
                fprintf(stderr, "エラー: オペランドが足りません\n");
                exit(1);
            }

            float right = pop();
            float left = pop();
            float r = calc(left, right, argv[i]);
            push(r);
        } else {
            push(atof(argv[i]));
        }
    }

    if (gSNum != 1){
        fprintf(stderr, "エラー: 数式が間違っています\n");
        exit(1);
    }

    printf("結果: %f\n", pop());
    return 0;
}
