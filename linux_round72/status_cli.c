#include <stdio.h>

enum StatusCode {
    STATUS_OK = 0,
    STATUS_USAGE_ERROR = 1,
    STATUS_FILE_ERROR = 2
};

const char *status_to_string(enum StatusCode status) {
    switch (status) {
        case STATUS_OK:
            return "OK";
        case STATUS_USAGE_ERROR:
            return "USAGE_ERROR";
        case STATUS_FILE_ERROR:
            return "FILE_ERROR";
        default:
            return "UNKNOWN_STATUS";
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        printf("status = %s\n", status_to_string(STATUS_USAGE_ERROR));
        return STATUS_USAGE_ERROR;
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL) {
        printf("Failed to open file: %s\n", argv[1]);
        printf("status = %s\n", status_to_string(STATUS_FILE_ERROR));
        return STATUS_FILE_ERROR;
    }

    printf("File opened successfully: %s\n", argv[1]);
    printf("status = %s\n", status_to_string(STATUS_OK));

    fclose(fp);

    return STATUS_OK;
}
