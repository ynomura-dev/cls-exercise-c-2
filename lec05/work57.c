#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(int argc, char *argv[]){
    int i;
    LIST_TYPE x;
    POSITION pos;

    for (i=1; i<argc; i++){
        if (strcmp(argv[i], "append") == 0){
    x = atoi(argv[++i]);
    printf("append(%d)\n", x);
    append(x);

    }else if (strcmp(argv[i], "insert") == 0){
        pos = atoi(argv[++i]);
        x = atoi(argv[++i]);
        printf("insert(%d, %d)\n", pos, x);
        insert(pos, x);

    }else if (strcmp(argv[i], "delete") == 0){
        pos = atoi(argv[++i]);
        printf("delete(%d)\n", pos);
        delete(pos);

    }else if (strcmp(argv[i], "retrive") == 0){
        pos = atoi(argv[++i]);
        printf("retrive(%d) => %d\n", pos, retrive(pos));
    }else if (strcmp(argv[i], "replace") == 0){
        pos = atoi(argv[++i]);
        x = atoi(argv[++i]);
        printf("replace(%d, %d) => %d\n", pos, x, replace(pos, x));
    }else{
        fprintf(stderr, "エラー: 不明な操作です(%s)\n", argv[i]);
        exit(1);
    }


        printf("  ==> ");
        printList();
    }
    
    printf("%d 個です", countPositiveMultipleOf3or5());

    return 0;
}