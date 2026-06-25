#include <stdio.h>

int main(void) {
    FILE *fp = fopen("output.txt", "w");

    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    fprintf(fp, "Linux Round 67\n");
    fprintf(fp, "C file writing practice\n");
    fprintf(fp, "score = %d\n", 95);

    fclose(fp);

    printf("File written successfully\n");

    return 0;
}
