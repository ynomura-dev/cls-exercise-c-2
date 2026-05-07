#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void errorExit(const char *message);

typedef float STACK_TYPE;
#define STACK_SIZE 10

void push(STACK_TYPE x);
STACK_TYPE pop(void);
void printStack(void);
int isStackEmpty(void);
int isStackFull(void);
int isEnteredINIT(char* n);
int initStack(void);
STACK_TYPE peek(void);

int isStackSingle(void);
int hasTwoElements(void);
int isGreaterThanPeek(STACK_TYPE x);
int isOperator(char* s);
STACK_TYPE calc(STACK_TYPE a, STACK_TYPE b, char *op);