#include <stdio.h>
#include <setjmp.h>
#include "error.h"
#include "lib1.h"
#include "infix_to_rpn.h"
#include "calc_rpn.h"
#define MAX_TOKEN_NUM 100

jmp_buf g_error_jmp;

int main(void){
    char *token[MAX_TOKEN_NUM];
    int num_tokens;

    num_tokens = enter(token, MAX_TOKEN_NUM);
    while (num_tokens > 0){
        if (setjmp(g_error_jmp) == 0){
            infix_to_rpn(token, num_tokens);
            calc_rpn();
        } else {
            fprintf(stderr, "An error occurred. Please try again.\n");
        }
        num_tokens = enter(token, MAX_TOKEN_NUM);
    }
    fprintf(stderr, "User requested exit.\n");
    return 0;
}
