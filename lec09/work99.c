#include <stdio.h>
#include <stdlib.h>

struct cell {
    int math;
    int english;
    struct cell *next;
};

struct cell g_front = {-1, -1, NULL};

void print_list(void) {
    printf("LIST[ ");
    for (struct cell *p = g_front.next; p != NULL; p = p->next) {
        printf("(%d %d) ", p->math, p->english);
    }
    printf("]\n");
}

void insert(struct cell *pre, struct cell *new) {
    new->next = pre->next;
    pre->next = new;
}

void get_highscore(int *max_math, int *max_english) {
    *max_math = -1;
    *max_english = -1;
    for (struct cell *p = g_front.next; p != NULL; p = p->next) {
        if (p->math > *max_math) *max_math = p->math;
        if (p->english > *max_english) *max_english = p->english;
    }
}

void get_mean(double *mean_math, double *mean_english) {
    int sum_math = 0, sum_english = 0, count = 0;
    for (struct cell *p = g_front.next; p != NULL; p = p->next) {
        sum_math += p->math;
        sum_english += p->english;
        count++;
    }
    *mean_math = count > 0 ? (double)sum_math / count : 0.0;
    *mean_english = count > 0 ? (double)sum_english / count : 0.0;
}

int main(void) {
    int math, english;
    struct cell *tail = &g_front;

    while (scanf("%d %d", &math, &english) == 2 && math >= 0 && english >= 0) {
        struct cell *p = malloc(sizeof(struct cell));
        if (p == NULL) {
            fprintf(stderr, "エラー: malloc失敗\n");
            exit(1);
        }
        p->math = math;
        p->english = english;
        insert(tail, p);
        tail = p;
        print_list();
    }

    int max_math, max_english;
    double mean_math, mean_english;
    get_highscore(&max_math, &max_english);
    get_mean(&mean_math, &mean_english);

    print_list();
    printf("数学  最大値: %d 平均値: %.2f\n", max_math, mean_math);
    printf("英語  最大値: %d 平均値: %.2f\n", max_english, mean_english);
    return 0;
}