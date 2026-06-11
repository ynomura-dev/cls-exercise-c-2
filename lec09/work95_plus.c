#include <stdio.h>
#include <stdlib.h>

struct cell {
    int value;
    struct cell *next;
};

struct cell gFront = {-1, NULL};

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

void printList(void) {
    struct cell *p;
    printf("LIST[ ");
    for (p = gFront.next; p != NULL; p = p->next) {
        printf("%d ", p->value);
    }
    printf("]\n");
}

int main(void) {
    int input_value;

    while (scanf("%d", &input_value) == 1 && input_value >= 0) {
        insert(&gFront, new_cell(input_value));
        printList();
    }

    printf("入力を終了しました\n");
    return 0;
}