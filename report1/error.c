#include <stdio.h>
#include <setjmp.h>

extern jmp_buf error_jmp;

void errorExit(const char *message){
    fprintf(stderr, "%s\n", message);
    longjmp(error_jmp, 1);
}
