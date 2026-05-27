#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "error.h"
#include "lib1.h"

void check_divisor(double divisor){
    if (divisor == 0) raise_error("error: check_divisor(): Division by zero");
}

double calculate(double a,double b, char *op){
    if (strcmp(op, "+") == 0) return a + b;
    if (strcmp(op, "-") == 0) return a - b;
    if (strcmp(op, "*") == 0) return a * b;
    if (strcmp(op, "/") == 0){
        check_divisor(b);
        return a / b;
    }
    if (strcmp(op, "%") == 0){
        check_divisor(b);
        return fmod(a, b);
    }
    if (strcmp(op, "^") == 0) return pow(a, b);
    raise_error("error: calculate(): invalid operator");
    return -1;
}

void calc_rpn(void){
    while (!is_queue_empty()){
    char *token = dequeue();
        if (isNumber(token)){
            push(token);
        } else if (isOperator(token)){
            double b = atof(pop());
            double a = atof(pop());
            double result = calculate(a, b, token);
            push(ftoa(result));
        } else {
            raise_error("error: calc_rpn(): invalid token");
        }
    }
    double result = atof(pop());
    // Output-end check: leftover operands mean an invalid expression (pairs with validate_infix()).
    if (!is_stack_empty()) raise_error("error: calc_rpn(): too many operands");
    printf("%f\n", result);
}