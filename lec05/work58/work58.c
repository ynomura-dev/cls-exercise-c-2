#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char *argv[]){
    int i;
    LIST_TYPE x;
    POSITION pos;

    if (argc < 2){
        errorExit("引数を指定してください");
        exit(1);
    }

    initList();

    for (i=1; i<argc; i++){
        x = atoi(argv[i]);
        sortedInsert(x);
    }
    return 0;
}