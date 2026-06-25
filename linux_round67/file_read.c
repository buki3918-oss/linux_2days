#include <stdio.h>

int main(void) {
    FILE *fp = fopen("output.txt", "r");

    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    char line[100];

    printf("Reading file:\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);

    return 0;
}
