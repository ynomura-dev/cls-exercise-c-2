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

/****************************************************************
* スタックの利用部分
*   - スタックの操作関数(push,pop)のみを用いる．
*   - 以下の通りに写す（コピー&ペーストしましょう）．
****************************************************************/
int main(void){
    printf("初期状態  : ");  printStack();
    printf("push(10)  : ");  push(10);  printStack();
    printf("push(20)  : ");  push(20);  printStack();
    printf("pop()     : ");  pop();     printStack();
    printf("push(30)  : ");  push(30);  printStack();
    printf("pop()     : ");  pop();     printStack();
    printf("pop()     : ");  pop();     printStack();
    printf("push(40)  : ");  push(40);  printStack();
    printf("push(50)  : ");  push(50);  printStack();
    printf("pop()     : ");  pop();     printStack();
    printf("push(60)  : ");  push(60);  printStack();
    printf("push(70)  : ");  push(70);  printStack();
    printf("最終状態  : ");  printStack();
}