#include <stdio.h>
#include <stdlib.h>

struct cell {
    int math;
    int english;
    struct cell *next;
};

struct cell gFront = {-1, -1, NULL};

void printList(void){
    struct cell *p;
    printf("LIST[ ");
    p = gFront.next;
    while (p != NULL){
        printf("(%d %d) ", p->math, p->english);
        p = p->next;
    }
    printf("]\n");
}

void insert(struct cell *pre, struct cell *new){
    new->next = pre->next;
    pre->next = new;
}

int main(void){
    int input_math;
    int input_english;
    struct cell *p;
    struct cell *p_tail = &gFront;

    scanf("%d %d", &input_math, &input_english);
    while (input_math >= 0||input_english >= 0){
        p = malloc(sizeof(struct cell));
        if (p == NULL){
            fprintf(stderr, "エラー: malloc失敗\n");
            exit(1);
        }
        p->math = input_math;
        p->english = input_english;
        insert(p_tail, p);
        p_tail = p;

        printList();
        scanf("%d %d", &input_math, &input_english);
    }

    printf("入力を終了しました\n");
    return 0;

}