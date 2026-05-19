#include <stdio.h>
#include <setjmp.h>
#include "error.h"
#include "lib1.h"
#include "infix_to_rpn.h"
#include "calc_rpn.h"
#define MAX_TOKEN_NUM 100

jmp_buf error_jmp;

int main(void){
    char *token[MAX_TOKEN_NUM];
    int numTokens;

    numTokens = enter(token, MAX_TOKEN_NUM);
    while (numTokens > 0){
        if (setjmp(error_jmp) == 0){
            infix_to_rpn(token, numTokens);
            calc_rpn();
        } else {
            fprintf(stderr, "An error occurred. Please try again.\n");
        }
        numTokens = enter(token, MAX_TOKEN_NUM);
    }
    fprintf(stderr, "User requested exit.\n");
    return 0;
}
