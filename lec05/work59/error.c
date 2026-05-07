#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void errorExit(const char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}