#include <stdio.h>
#include <stdlib.h>

struct cell {
    int value;
    struct cell *next;
};

struct cell gFront = {-1, NULL};

void printList(void){
    struct cell *p;
    printf("LIST[ ");
    p = gFront.next;
    while (p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }
    printf("]\n");
}

void insert(struct cell *pre, struct cell *new){
    new->next = pre->next;
    pre->next = new;
}

int main(void){
    int input_value;
    struct cell *p;
    struct cell *tail = &gFront;

    scanf("%d", &input_value);
    while (input_value >= 0){
        p = malloc(sizeof(struct cell));
        if (p == NULL){
            fprintf(stderr, "エラー: malloc失敗\n");
            exit(1);
        }
        p->value = input_value;
        insert(tail, p);
        tail = p;

        printList();
        scanf("%d", &input_value);
    }

    printf("入力を終了しました\n");
    return 0;
}