#include <stdio.h>
#include <stdlib.h>

struct cell {
    int value;
    struct cell *next;
};

struct cell g_front = {-1, NULL};

struct cell *new_cell(int value) {
    struct cell *p = malloc(sizeof(struct cell));
    if (p == NULL) {
        fprintf(stderr, "エラー: malloc失敗\n");
        exit(1);
    }
    p->value = value;
    p->next = NULL;
    return p;
}

void insert(struct cell *pre, struct cell *new) {
    new->next = pre->next;
    pre->next = new;
}

void print_list(void) {
    printf("LIST[ ");
    for (struct cell *p = g_front.next; p != NULL; p = p->next) {
        printf("%d ", p->value);
    }
    printf("]\n");
}

int main(void) {
    int input_value;
    struct cell *tail = &g_front;

    while (scanf("%d", &input_value) == 1 && input_value >= 0) {
        struct cell *p = new_cell(input_value);
        insert(tail, p);
        tail = p;
        print_list();
    }

    printf("入力を終了しました\n");
    return 0;
}