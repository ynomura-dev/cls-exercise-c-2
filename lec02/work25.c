#include <stdio.h>
#define STACK_SIZE 10

/****************************************************************
* スタックの実装部分
*   - push操作とpop操作は関数として実現する．
*   - スタックのデータ格納領域はグローバル変数として宣言する．
*     そうすることで，push関数とpop関数の両方から参照可能となる．
****************************************************************/
int gStack[STACK_SIZE];  /* スタックを表す配列 */
int gSNum = 0;           /* スタックに格納されているデータ数 */

/* スタックにデータをプッシュする関数 */
/* ★教科書などを参考に自分で作る */

void push(int x){
    gStack[gSNum] = x;
    gSNum ++;
}

/* スタックからデータをポップする関数 */
/* ★教科書などを参考に自分で作る */

int pop(void){
    int x = gStack[gSNum - 1];

    gSNum--;
    return x;
}

/* スタックの内容を表示する関数 */
void printStack(void){
    int i = 0;

    printf("STACK[");
    for(i = 0; i < gSNum; i++){
        printf(" %d", gStack[i]);
        if(i != gSNum - 1) printf(" ");
    }
    printf(" ]\n");
}

int isStackEmpty(){
    return gSNum == 0;
}

int isStackFull(){
    return gSNum == STACK_SIZE;
}

/****************************************************************
* スタックの利用部分
*   - スタックの操作関数(push,pop)のみを用いる．
*   - 以下の通りに写す（コピー&ペーストしましょう）．
****************************************************************/
int main(void){
    int tmp;

    // スタックがフル状態でない間，キーボード入力した整数をpushする
    while (!isStackFull()){     // 「!」は論理否定を表す演算子である
        scanf("%d", &tmp);
        push(tmp);
        printf("push %2d : ", tmp);
        printStack();
    }

    printf("=================\n");

    // スタックが空状態になるまで（=空状態でない間）popし続ける
    while (!isStackEmpty()){
        printf("pop %2d : ", pop());
        printStack();
    }

    return 0;
}