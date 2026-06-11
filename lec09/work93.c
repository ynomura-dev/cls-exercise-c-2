#include <stdio.h>
#include <stdlib.h>

struct cell {
    int value;
    struct cell *next;
};

struct cell g_head = {0, NULL};

void print_list(void){
    struct cell *p;
    printf("LIST[");
    p = g_head.next;
    while (p != NULL){
        printf("%d", p->value);
        if (p->next != NULL) printf(", ");
        p = p->next;
    }
    printf("]\n");
}

int sum_list(void){
    struct cell *p;
    int sum = 0;
    p = g_head.next;
    while (p != NULL){
        sum += p->value;
        p = p->next;
    }
    return sum;
}

int main(void){
    struct cell *c1;
    struct cell *c2;
    struct cell *c3;

    c1 = malloc(sizeof(struct cell));       //mallocを使いたいからポインタで宣言する
    c1->value = 1;
    c2 = malloc(sizeof(struct cell));
    c2->value = 2;
    c3 = malloc(sizeof(struct cell));
    c3->value = 3;

    g_head.next = c1;
    c1->next = c2;
    c2->next = c3;
    c3->next = NULL;

    print_list();
    printf("%d\n", sum_list());
    return 0;
}