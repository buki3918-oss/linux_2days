#include <stdio.h>
#include "student.h"

const char *get_result(int score) {
    if (score >= 60) {
        return "PASS";
    }

    return "FAIL";
}

void write_report_header(FILE *out) {
    fprintf(out, "Student Report\n");
    fprintf(out, "==============\n");
}

void write_student(FILE *out, struct Student *s) {
    fprintf(out, "id = %d, name = %s, score = %d, result = %s\n",
            s->id, s->name, s->score, get_result(s->score));
}

void print_student(struct Student *s) {
    printf("id = %d, name = %s, score = %d, result = %s\n",
           s->id, s->name, s->score, get_result(s->score));
}

