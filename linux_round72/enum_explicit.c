#include <stdio.h>

enum StatusCode {
    STATUS_OK = 0,
    STATUS_USAGE_ERROR = 1,
    STATUS_FILE_ERROR = 2,
    STATUS_MEMORY_ERROR = 3
};

const char *status_to_string(enum StatusCode status) {
    switch (status) {
        case STATUS_OK:
            return "OK";
        case STATUS_USAGE_ERROR:
            return "USAGE_ERROR";
        case STATUS_FILE_ERROR:
            return "FILE_ERROR";
        case STATUS_MEMORY_ERROR:
            return "MEMORY_ERROR";
        default:
            return "UNKNOWN_STATUS";
    }
}

int main(void) {
    enum StatusCode status = STATUS_FILE_ERROR;

    printf("status code = %d\n", status);
    printf("status name = %s\n", status_to_string(status));

    return status;
}
