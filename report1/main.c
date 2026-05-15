#include "error.h"
#include "lib1.h"
#include "infix_to_rpn.h"

#define MAX_TOKEN_NUM 100

int main(void){
    char *token[MAX_TOKEN_NUM];
    int numTokens;

    numTokens = enter(token, MAX_TOKEN_NUM);
    while (numTokens > 0){      // if numTokens <= 0, user requested exit (because of enter function)
        infix_to_rpn(token, numTokens);
        numTokens = enter(token, MAX_TOKEN_NUM);
    }
    errorExit("User requested exit.");
    return -1;
}