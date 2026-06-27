#ifndef STUDENT_H
#define STUDENT_H

#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int score;
};

void write_report_header(FILE *out);
void write_student(FILE *out, struct Student *s);
void print_student(struct Student *s);
const char *get_result(int score);

#endif
