#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *s;
    char *p;

    s = malloc(sizeof(char) * 12);
    if (s == NULL) {
        fprintf(stderr, "エラー： malloc失敗\n");
        exit(1);
    }
    scanf("%s", s);
    printf("s = %s\n", s);
    p = s;
    printf("p = %s\n", p);

    free(s);
    return 0;
}