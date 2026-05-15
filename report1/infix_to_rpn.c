#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "error.h"
#include "lib1.h"

int priority(char *op){
    if (strcmp(op, "+") == 0 || strcmp(op, "-") == 0) return 1;
    if (strcmp(op, "*") == 0 || strcmp(op, "/") == 0 || strcmp(op, "%") == 0) return 2;
    if (strcmp(op, "^") == 0) return 3;
    errorExit("error: priority(): invalid operator");
    return -1;
}

void validateInfix(char *token[], int numTokens){
    char *prev = NULL;
    for (int i = 0; i < numTokens; i++){
        char *cur = token[i];
        if (isOperator(cur)){
            if (prev == NULL || isOperator(prev) || strcmp(prev, "(") == 0)
                errorExit("error: validateInfix(): Invalid expression");
        }
        prev = cur;
    }
    if (prev == NULL || isOperator(prev))
        errorExit("error: validateInfix(): Invalid expression");
}      //write about this later. <- did it :)

void infix_to_rpn(char *token[], int numTokens){
    validateInfix(token, numTokens);
    initStack();
    initQueue();

    for (int tokenIdx = 0; tokenIdx < numTokens; tokenIdx++){
        char *cur = token[tokenIdx];

        if (isNumber(cur)){
            enqueue(cur);
        } else if (strcmp(cur, "(") == 0){
            push(cur);
        } else if (strcmp(cur, ")") == 0){
            while (!isStackEmpty() && strcmp(peek(), "(") != 0){
                enqueue(pop());
            }
            if (isStackEmpty()){
                errorExit("error: infix_to_rpn(): Paren mismatch");
            }
            pop();
        } else if (isOperator(cur)){
            int isRightAssoc = (strcmp(cur, "^") == 0);
            if (isRightAssoc){
                while (!isStackEmpty() && strcmp(peek(), "(") != 0 && priority(peek()) > priority(cur))
                    enqueue(pop());
            } else {
                while (!isStackEmpty() && strcmp(peek(), "(") != 0 && priority(peek()) >= priority(cur))
                    enqueue(pop());
            }
            push(cur);
        } else {
            errorExit("error: infix_to_rpn(): invalid token");
        }
    }
    while (!isStackEmpty()){
        enqueue(pop());
    }
    printQueue();
}

