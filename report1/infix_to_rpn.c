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
    raise_error("error: priority(): invalid operator");
    return -1;
}

// Input-end syntax check. Operand count (e.g. "1 2 3") is checked at the end of calc_rpn().
void validate_infix(char *token[], int num_tokens){
    char *prev = NULL;
    for (int i = 0; i < num_tokens; i++){
        char *cur = token[i];
        if (isOperator(cur)){
            if (prev == NULL || isOperator(prev) || strcmp(prev, "(") == 0)
                raise_error("error: validate_infix(): Invalid expression");
        }
        prev = cur;
    }
    if (prev == NULL || isOperator(prev))
        raise_error("error: validate_infix(): Invalid expression");
}      //write about this later. <- did it :)

void infix_to_rpn(char *token[], int num_tokens){
    validate_infix(token, num_tokens);
    init_stack();
    init_queue();

    for (int token_idx = 0; token_idx < num_tokens; token_idx++){
        char *cur = token[token_idx];

 
        if (isNumber(cur)){
            enqueue(cur);
        } else if (strcmp(cur, "(") == 0){
            push(cur);
        } else if (strcmp(cur, ")") == 0){
            while (!is_stack_empty() && strcmp(peek(), "(") != 0){
                enqueue(pop());
            }
            if (is_stack_empty()){
                raise_error("error: infix_to_rpn(): invalid expression: missing '('");
            }
            pop();
        } else if (isOperator(cur)){
            int is_right_assoc = (strcmp(cur, "^") == 0);
            if (is_right_assoc){
                while (!is_stack_empty() && strcmp(peek(), "(") != 0 && priority(peek()) > priority(cur))
                    enqueue(pop());
            } else {
                while (!is_stack_empty() && strcmp(peek(), "(") != 0 && priority(peek()) >= priority(cur))
                    enqueue(pop());
            }
            push(cur);
        } else {
            raise_error("error: infix_to_rpn(): invalid token");
        }
    }
    while (!is_stack_empty()){
        char *top = pop();

        if (strcmp(top, "(") == 0){
            raise_error("error: infix_to_rpn(): invalid expression: missing ')'");
        } else {
            enqueue(top);
        }
    }
    print_queue();
}


