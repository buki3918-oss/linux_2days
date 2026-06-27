#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[50];
    int score;
};

void print_student(struct Student *s) {
    const char *result;

    if (s->score >= 60) {
        result = "PASS";
    } else {
        result = "FAIL";
    }

    printf("id = %d, name = %s, score = %d, result = %s\n",
           s->id, s->name, s->score, result);
}

int main(void) {
    FILE *fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("Failed to open students.txt\n");
        return 1;
    }

    int capacity = 2;
    int count = 0;

    struct Student *students = malloc(capacity * sizeof(struct Student));

    if (students == NULL) {
        printf("malloc failed\n");
        fclose(fp);
        return 1;
    }

    while (fscanf(fp, "%d %49s %d",
                  &students[count].id,
                  students[count].name,
                  &students[count].score) == 3) {
        count++;

        if (count == capacity) {
            int new_capacity = capacity * 2;

            struct Student *new_students =
                realloc(students, new_capacity * sizeof(struct Student));

            if (new_students == NULL) {
                printf("realloc failed\n");
                free(students);
                fclose(fp);
                return 1;
            }

            students = new_students;
            capacity = new_capacity;

            printf("Expanded capacity to %d\n", capacity);
        }
    }

    fclose(fp);

    printf("\nStudent List:\n");
    for (int i = 0; i < count; i++) {
        print_student(&students[i]);
    }

    printf("\nSummary:\n");
    printf("count = %d\n", count);
    printf("capacity = %d\n", capacity);

    free(students);

    return 0;
}
