#include <stdio.h>
#include <stdlib.h>
#include "myerror.h"

void error(char *message){
    fprintf(stderr, "エラー: %s\n", message);
    exit(1);
}