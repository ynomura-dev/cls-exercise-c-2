#include <stdio.h>
#include <stdlib.h>

void errorExit(const char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}