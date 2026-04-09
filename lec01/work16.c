#include <stdio.h>
#include <string.h>
#define NUM 12

int priority(char *operator){
    if (strcmp(operator, "||") == 0) return 1;
    if (strcmp(operator, "&&") == 0) return 2;
    if (strcmp(operator, "==") == 0) return 3;
    if (strcmp(operator, "+")  == 0) return 5;
    if (strcmp(operator, "-")  == 0) return 5;
    if (strcmp(operator, "*")  == 0) return 6;
    if (strcmp(operator, "/")  == 0) return 6;
    if (strcmp(operator, "%")  == 0) return 6;
    if (strcmp(operator, "^")  == 0) return 8;
    return -1;
}

int main(void){
    char *oplist[NUM] = {"+", "-", "*", "/", "^", "%", "&", "=", "&&", "||", "==", "<="};
    int i;

    for (i=0; i<NUM; i++){
        printf("%s ==> %d\n",oplist[i], priority(oplist[i]));

    }
    
    return 0;
}