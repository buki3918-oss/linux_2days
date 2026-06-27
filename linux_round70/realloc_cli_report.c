#include <stdio.h>
#include <stdlib.h>

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

    int capacity = 2;
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
            int new_capacity = capacity * 2;

            struct Student *new_students =
                realloc(students, new_capacity * sizeof(struct Student));

            if (new_students == NULL) {
                printf("realloc failed\n");
                free(students);
                fclose(in);
                return 1;
            }

            students = new_students;
            capacity = new_capacity;
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

    int total = 0;

    for (int i = 0; i < count; i++) {
        write_student(out, &students[i]);
        total += students[i].score;
    }

    double average = 0.0;

    if (count > 0) {
        average = (double)total / count;
    }

    fprintf(out, "\nSummary\n");
    fprintf(out, "=======\n");
    fprintf(out, "Total students = %d\n", count);
    fprintf(out, "Average score = %.2f\n", average);
    fprintf(out, "Final capacity = %d\n", capacity);

    fclose(out);
    free(students);

    printf("Report generated: %s\n", output_file);

    return 0;
}
