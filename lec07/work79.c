#include <stdio.h>


struct Student {
    char name[64];
    char id[64];
    int credits;
    int grad_flag;
};

int make_student_list(struct Student *students, int n){
    for (int i=0; i<n; i++){
        scanf("%s", students[i].name);
        scanf("%s", students[i].id);
        scanf("%d", &students[i].credits);
        scanf("%d", &students[i].grad_flag);
    }
    return 0;
}

int print_student_list(struct Student *students, int n){
    for (int i=0; i<n; i++){
        printf("====[%s]====\n学番: %s\n単位: %d\n卒業: %d\n\n",
            students[i].name, students[i].id, students[i].credits, students[i].grad_flag);
    }
    return 0;
}

int main(void){
    int n;
    scanf("%d", &n);
    struct Student students[n];
    make_student_list(students, n);
    print_student_list(students, n);
    return 0;
}