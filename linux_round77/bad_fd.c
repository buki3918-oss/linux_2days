#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void) {
    const char *message = "hello\n";

    ssize_t result = write(9999, message, 6);

    if (result == -1) {
        perror("write");
        printf("errno = %d\n", errno);
        printf("strerror = %s\n", strerror(errno));
        return 1;
    }

    return 0;
}
