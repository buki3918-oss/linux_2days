#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    int score;
};

void write_report_header(FILE *out) {
    fprintf(out, "Student Report\n");
    fprintf(out, "==============\n");
}

void write_student(FILE *out, struct Student *s) {
    const char *result;

    if (s->score >= 60) {
        result = "PASS";
    } else {
        result = "FAIL";
    }

    fprintf(out, "id = %d, name = %s, score = %d, result = %s\n",
            s->id, s->name, s->score, result);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *in = fopen(input_file, "r");

    if (in == NULL) {
        printf("Failed to open input file: %s\n", input_file);
        return 1;
    }

    int capacity = 4;
    int count = 0;

    struct Student *students = malloc(capacity * sizeof(struct Student));

    if (students == NULL) {
        printf("malloc failed\n");
        fclose(in);
        return 1;
    }

    while (fscanf(in, "%d %49s %d",
                  &students[count].id,
                  students[count].name,
                  &students[count].score) == 3) {
        count++;

        if (count == capacity) {
            capacity = capacity * 2;

            struct Student *new_students =
                malloc(capacity * sizeof(struct Student));

            if (new_students == NULL) {
                printf("malloc failed\n");
                free(students);
                fclose(in);
                return 1;
            }

            for (int i = 0; i < count; i++) {
                new_students[i] = students[i];
            }

            free(students);
            students = new_students;
        }
    }

    fclose(in);

    FILE *out = fopen(output_file, "w");

    if (out == NULL) {
        printf("Failed to open output file: %s\n", output_file);
        free(students);
        return 1;
    }

    write_report_header(out);

    for (int i = 0; i < count; i++) {
        write_student(out, &students[i]);
    }

    fprintf(out, "\nTotal students = %d\n", count);

    fclose(out);
    free(students);

    printf("Report generated: %s\n", output_file);

    return 0;
}
