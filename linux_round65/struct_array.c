#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    int score;
};

void print_student(struct Student *s) {
    printf("id = %d, name = %s, score = %d\n", s->id, s->name, s->score);
}

int main(void) {
    struct Student students[3];

    students[0].id = 1;
    strcpy(students[0].name, "Sunny");
    students[0].score = 90;

    students[1].id = 2;
    strcpy(students[1].name, "Yichieh");
    students[1].score = 85;

    students[2].id = 3;
    strcpy(students[2].name, "Alex");
    students[2].score = 78;

    printf("Student List:\n");
    for (int i = 0; i < 3; i++) {
        print_student(&students[i]);
    }

    printf("\nAddresses:\n");
    for (int i = 0; i < 3; i++) {
        printf("&students[%d] = %p\n", i, (void *)&students[i]);
    }

    printf("\nSize:\n");
    printf("sizeof(struct Student) = %zu\n", sizeof(struct Student));
    printf("sizeof(students) = %zu\n", sizeof(students));

    return 0;
}
