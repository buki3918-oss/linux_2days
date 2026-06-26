#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <output_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "w");

    if (fp == NULL) {
        printf("Failed to open file: %s\n", argv[1]);
        return 1;
    }

    fprintf(fp, "This file was created by file_arg_writer.\n");
    fprintf(fp, "Output filename: %s\n", argv[1]);

    fclose(fp);

    printf("File created: %s\n", argv[1]);

    return 0;
}
