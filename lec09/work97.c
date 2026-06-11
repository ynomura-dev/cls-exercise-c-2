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

double mean_list(void){
    struct cell *p;
    int sum = 0;
    int count = 0;
    p = gFront.next;
    while (p != NULL){
        sum += p->value;
        count++;
        p = p->next;
    }
    if (count == 0) return 0.0; // avoid division by zero
    return (double)sum / count;
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
    printf("平均値: %.2f\n", mean_list());
    return 0;

}