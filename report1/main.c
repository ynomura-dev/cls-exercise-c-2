#include "error.h"
#include "lib1.h"
#include "infix_to_rpn.h"

#define MAX_TOKEN_NUM 100

int main(void){
    char *token[MAX_TOKEN_NUM];
    int numTokens, i;

    numTokens = enter(token, MAX_TOKEN_NUM);    /* tokenに分割結果を格納し、トークン数を返す */
    while (numTokens > 0){
        infix_to_rpn(token, numTokens);

        /*debug
        printQueue(0);
        printStack();
        */

        numTokens = enter(token, MAX_TOKEN_NUM);  /* 次の入力 */
    }
    errorExit("User requested exit.");
    return -1;

    

}