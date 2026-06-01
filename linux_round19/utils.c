#include <stdio.h>
#include "utils.h"

void print_project_info() {
    printf("=== Multi-file C Project ===\n");
    printf("This project uses main.c, utils.c, and utils.h.\n");
}

int add(int a, int b) {
    return a + b;
}
