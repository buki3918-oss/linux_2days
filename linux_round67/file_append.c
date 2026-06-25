#include <stdio.h>

int main(void) {
    FILE *fp = fopen("output.txt", "a");

    if (fp == NULL) {
        printf("Failed to open file\n");
        return 1;
    }

    fprintf(fp, "Append line 1\n");
    fprintf(fp, "Append line 2\n");

    fclose(fp);

    printf("File appended successfully\n");

    return 0;
}
