#include <stdio.h>
#include <stdlib.h>

struct cell {
    int value;
    struct cell *next;
};

struct cell g_head = {0, NULL};

int main(void){
    struct cell *c1;
    struct cell *c2;
    struct cell *c3;

    c1 = malloc(sizeof(struct cell));
    c1->value = 1;
    c2 = malloc(sizeof(struct cell));
    c2->value = 2;
    c3 = malloc(sizeof(struct cell));
    c3->value = 3;

    g_head.next = c1;
    c1->next = c2;
    c2->next = c3;
    c3->next = NULL;

    return 0;
}