#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]){
    int i;
    if (argc < 2){
        errorExit("エラー: プログラム引数がありません");
    }

    initStack();

    for (i = 1; i < argc; i++){
        char *token = argv[i];
        if (isOperator(token)){
            if (!hasTwoElements()){
                errorExit("エラー: 数式が間違っています");
            }
            float b = pop();
            float a = pop();
            float r = calc(a, b, token);
            push(r);
        }
        else {
            float value = atof(token);      //ここがatofなので、あえてfloatで定義している
            push(value);
        }
    }

    if (!isStackSingle()){
        errorExit("エラー: 数式が間違っています");
    }

    printf("結果: %f\n", pop());
    return 0;
}
