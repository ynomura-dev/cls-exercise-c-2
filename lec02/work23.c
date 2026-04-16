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

/****************************************************************
* スタックの利用部分
*   - スタックの操作関数(push,pop)のみを用いる．
*   - 以下の通りに写す（コピー&ペーストしましょう）．
****************************************************************/
int main(void){
    printf("100をpushします\n");   push(100);
    printf("200をpushします\n");   push(200);
    printf("  %dをpopしました\n",  pop());
    printf("300をpushします\n");   push(300);
    printf("400をpushします\n");   push(400);
    printf("  %dをpopしました\n",  pop());
    printf("  %dをpopしました\n",  pop());
    printf("500をpushします\n");   push(500);
    printf("600をpushします\n");   push(600);
    printf("  %dをpopしました\n",  pop());
    printf("  %dをpopしました\n",  pop());
    printf("  %dをpopしました\n",  pop());
    printf("700をpushします\n");   push(700);
    return 0;
}