#include <stdio.h>
#include <stdlib.h>

struct record {
    char zipcode[8];
    char govcode[8];
    char address[150];
    char furigana[256];
};

void read_address(struct record *r) {
    scanf("%s", r->zipcode);
    scanf("%s", r->govcode);
    scanf("%s", r->address);
    scanf("%s", r->furigana);
}

void print_address(struct record *r) {
    printf("〒%s", r->zipcode);
    printf(" %s\n", r->address);
}

int main(void) {
    int num;
    scanf("%d", &num);

    struct record *records = malloc(num * sizeof(struct record));
    if (records == NULL) {
        fprintf(stderr, "エラー： malloc失敗\n");
        exit(1);
    }

    for (int i = 0; i < num; i++) {
        read_address(&records[i]);
    }

    for (int i = 0; i < num; i++) {
        print_address(&records[i]);
    }

    free(records);
    return 0;
}