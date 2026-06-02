#include <stdio.h>
#define MAX_N 1000   /* 受講者の最大数 */

struct student {
    char id[8];
    char family_name[32];
    char given_name[32];
    int score_test1;
    int score_test2;
    int score_exam;
    int score_report1;
    int score_report2;
    int absences;
    int grade;
};

int max3(int a, int b, int c) {     //作るべきじゃないけどめんどくて()
    int m = a;
    if (b > m) m = b;
    if (c > m) m = c;
    return m;
}

void read_data(struct student *s){
    scanf("%s", s->id);
    scanf("%s", s->family_name);
    scanf("%s", s->given_name);
    scanf("%d", &s->score_test1);
    scanf("%d", &s->score_test2);
    scanf("%d", &s->score_exam);
    scanf("%d", &s->score_report1);
    scanf("%d", &s->score_report2);
    scanf("%d", &s->absences);
}

int evaluate_grade(struct student s){
    if (s.absences >= 4) {
        return 1;
    }

    int test_sum = s.score_test1 + s.score_test2;
    int report_sum = s.score_report1 + s.score_report2;
    int best_test = max3(s.score_test1, s.score_test2, s.score_exam);

    if (test_sum >= 40 &&
        s.score_exam >= 40 &&
        report_sum >= 40) {
        return 3;
    }

    if (best_test + report_sum >= 60) {
        return 2;
    }

    return 1;
}


double calc_average_exam(struct student students[], int n){
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].score_exam;
    }
    return sum / n;
}

void print_max_report(struct student students[], int n){
    int max_score = -1;
    int max_index = -1;
    for (int i = 0; i < n; i++) {
        int total_report_score = students[i].score_report1 + students[i].score_report2;
        if (total_report_score > max_score) {
            max_score = total_report_score;
            max_index = i;
        }
    }
    if (max_index != -1) {
        printf("最高点の学生: %s %s, 学番: %s, レポート点: %d\n",
               students[max_index].family_name,
               students[max_index].given_name,
               students[max_index].id,
               max_score);
    }
}

int main(void){
    struct student students[MAX_N];
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        read_data(&students[i]);
        students[i].grade = evaluate_grade(students[i]);
    }

    int count_grade[4] = {0};
    for (int i = 0; i < n; i++) {
        count_grade[students[i].grade]++;
    }
    printf("成績1の人数: %d\n", count_grade[1]);
    printf("成績2の人数: %d\n", count_grade[2]);
    printf("成績3の人数: %d\n", count_grade[3]);

    printf("成績3の人の学番と氏名の一覧:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].grade == 3) {
            printf("学番: %s, 氏名: %s %s\n", students[i].id, students[i].family_name, students[i].given_name);
        }
    }
    printf("期末テストの平均点: %.2f\n", calc_average_exam(students, n));

    print_max_report(students, n);

    return 0;
}