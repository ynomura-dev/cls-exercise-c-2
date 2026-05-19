#include <stdio.h>
#include <setjmp.h>

extern jmp_buf g_error_jmp;

void raiseError(const char *message){
    fprintf(stderr, "%s\n", message);
    longjmp(g_error_jmp, 1);
}
