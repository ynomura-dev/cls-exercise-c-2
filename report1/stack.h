#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define STACK_SIZE 1000
typedef char* STACK_TYPE; 


void push(STACK_TYPE x);
STACK_TYPE pop(void);
void printStack(void);
int isStackEmpty(void);
int isStackFull(void);
void initStack(void);
STACK_TYPE peek(void);
