#include <stdio.h>
#include <stdlib.h>

enum StatusCode {
    STATUS_OK = 0,
    STATUS_USAGE_ERROR = 1,
    STATUS_INPUT_FILE_ERROR = 2,
    STATUS_OUTPUT_FILE_ERROR = 3,
    STATUS_MEMORY_ERROR = 4
};

enum Result {
    RESULT_PASS,
    RESULT_FAIL
};

struct Student {
    int id;
    char name[50];
    int score;
};

const char *status_to_string(enum StatusCode status) {
    switch (status) {
        case STATUS_OK:
            return "OK";
        case STATUS_USAGE_ERROR:
            return "USAGE_ERROR";
        case STATUS_INPUT_FILE_ERROR:
            return "INPUT_FILE_ERROR";
        case STATUS_OUTPUT_FILE_ERROR:
            return "OUTPUT_FILE_ERROR";
        case STATUS_MEMORY_ERROR:
            return "MEMORY_ERROR";
        default:
            return "UNKNOWN_STATUS";
    }
}

enum Result get_result(int score) {
    if (score >= 60) {
        return RESULT_PASS;
    }

    return RESULT_FAIL;
}

const char *result_to_string(enum Result result) {
    switch (result) {
        case RESULT_PASS:
            return "PASS";
        case RESULT_FAIL:
            return "FAIL";
        default:
            return "UNKNOWN_RESULT";
    }
}

void write_report_header(FILE *out) {
    fprintf(out, "Student Report\n");
    fprintf(out, "==============\n");
}

void write_student(FILE *out, struct Student *s) {
    enum Result result = get_result(s->score);

    fprintf(out, "id = %d, name = %s, score = %d, result = %s\n",
            s->id, s->name, s->score, result_to_string(result));
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        printf("status = %s\n", status_to_string(STATUS_USAGE_ERROR));
        return STATUS_USAGE_ERROR;
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *in = fopen(input_file, "r");

    if (in == NULL) {
        printf("Failed to open input file: %s\n", input_file);
        printf("status = %s\n", status_to_string(STATUS_INPUT_FILE_ERROR));
        return STATUS_INPUT_FILE_ERROR;
    }

    int capacity = 2;
    int count = 0;

    struct Student *students = malloc(capacity * sizeof(struct Student));

    if (students == NULL) {
        printf("malloc failed\n");
        printf("status = %s\n", status_to_string(STATUS_MEMORY_ERROR));
        fclose(in);
        return STATUS_MEMORY_ERROR;
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
                printf("status = %s\n", status_to_string(STATUS_MEMORY_ERROR));
                free(students);
                fclose(in);
                return STATUS_MEMORY_ERROR;
            }

            students = new_students;
            capacity = new_capacity;
        }
    }

    fclose(in);

    FILE *out = fopen(output_file, "w");

    if (out == NULL) {
        printf("Failed to open output file: %s\n", output_file);
        printf("status = %s\n", status_to_string(STATUS_OUTPUT_FILE_ERROR));
        free(students);
        return STATUS_OUTPUT_FILE_ERROR;
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
    printf("status = %s\n", status_to_string(STATUS_OK));

    return STATUS_OK;
}
