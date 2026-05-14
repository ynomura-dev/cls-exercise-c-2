#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "error.h"
#include "lib1.h"

int priority(char op){
    if (op == '+' || op == '-') return 5;
    if (op == '*' || op == '/' || op == '%') return 6;
    if (op == '^') return 8;
    errorExit("error: priority(): invalid operator");
    return -1;
}

void infix_to_rpn(char *token[], int numTokens){
    initStack();
    initQueue();

    for (int tokenIdx = 0; tokenIdx < numTokens; tokenIdx++){
        if (isNumber(token[tokenIdx])){
            enqueue(token[tokenIdx][0]);
        } else if (isOperator(token[tokenIdx])){
            int isRightAssoc = (token[tokenIdx][0] == '^');
            while (!isStackEmpty() && (isRightAssoc
                ? priority(peek()) > priority(token[tokenIdx][0])
                : priority(peek()) >= priority(token[tokenIdx][0]))){
                enqueue(pop());
            }
            push(token[tokenIdx][0]);
        } else {
            errorExit("error: infix_to_rpn(): invalid token");
        }
    }
    while (!isStackEmpty()){
        enqueue(pop());
    }
    printQueue(0);
}

