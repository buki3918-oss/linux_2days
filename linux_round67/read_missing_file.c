#include <stdio.h>

int main(void) {
    FILE *fp = fopen("missing.txt", "r");

    if (fp == NULL) {
        printf("Failed to open missing.txt\n");
        return 1;
    }

    fclose(fp);

    return 0;
}
