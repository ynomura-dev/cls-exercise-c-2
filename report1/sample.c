#include <stdio.h>
#include "lib1.h"          // ←補助プログラムを使用するために必要
#define MAX_TOKEN_NUM 100  // ←１回の入力で分割できるトークンの最大数

int main(void){
    char *token[MAX_TOKEN_NUM];  // ←分割したトークンを格納する配列
    int tnum, i;

    tnum = enter(token, MAX_TOKEN_NUM);    /* 最初の入力 */
    while (tnum > 0){

        /* トークンを先頭から１つずつ表示する */
        for (i=0; i<tnum; i++){
            printf("token[%d]:%-4s  ", i, token[i]);
            printf("isNumber:%d  ", isNumber(token[i]));
            printf("isOperator:%d\n", isOperator(token[i]));
        }

        tnum = enter(token, MAX_TOKEN_NUM);  /* 次の入力 */
    }
    return 0;
}