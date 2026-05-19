#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "error.h"
#include "lib1.h"

void checkDivisor(double b){
    if (b == 0) errorExit("error: checkDivisor(): Division by zero");
}

double calculate(double a,double b, char *op){
    if (strcmp(op, "+") == 0) return a + b;
    if (strcmp(op, "-") == 0) return a - b;
    if (strcmp(op, "*") == 0) return a * b;
    if (strcmp(op, "/") == 0){
        checkDivisor(b);
        return a / b;
    }
    if (strcmp(op, "%") == 0){
        checkDivisor(b);
        return fmod(a, b);
    }
    if (strcmp(op, "^") == 0) return pow(a, b);
    errorExit("error: calculate(): invalid operator");
    return 0;
}

void calc_rpn(void){
    while (!isQueueEmpty()){
    char *token = dequeue();
        if (isNumber(token)){
            push(token);
        } else if (isOperator(token)){
            double b = atof(pop());
            double a = atof(pop());
            double result = calculate(a, b, token);
            push(ftoa(result));
        } else {
            errorExit("error: calc_rpn(): invalid token");
        }
    }
    double result = atof(pop());
    if (!isStackEmpty()) errorExit("error: calc_rpn(): too many operands");
    printf("%f\n", result);
}