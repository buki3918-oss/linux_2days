#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    int score;
};

void write_student(FILE *fp, struct Student *s) {
    fprintf(fp, "id = %d, name = %s, score = %d\n",
            s->id, s->name, s->score);
}

int main(void) {
    struct Student students[3];

    students[0].id = 1;
    strcpy(students[0].name, "Sunny");
    students[0].score = 90;

    students[1].id = 2;
    strcpy(students[1].name, "Yichieh");
    students[1].score = 95;

    students[2].id = 3;
    strcpy(students[2].name, "Alex");
    students[2].score = 80;

    FILE *fp = fopen("student_report.txt", "w");

    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    fprintf(fp, "Student Report\n");
    fprintf(fp, "==============\n");

    for (int i = 0; i < 3; i++) {
        write_student(fp, &students[i]);
    }

    fclose(fp);

    printf("student_report.txt generated\n");

    return 0;
}
