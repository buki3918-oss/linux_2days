#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void) {
    int fd = open("/dev/null", O_WRONLY);

    if (fd == -1) {
        perror("open /dev/null");
        printf("errno = %d, message = %s\n", errno, strerror(errno));
        return 1;
    }

    const char *message = "This message goes to /dev/null.\n";

    ssize_t bytes_written = write(fd, message, 33);

    if (bytes_written == -1) {
        perror("write /dev/null");
        printf("errno = %d, message = %s\n", errno, strerror(errno));
        close(fd);
        return 1;
    }

    printf("bytes_written = %zd\n", bytes_written);

    if (close(fd) == -1) {
        perror("close /dev/null");
        printf("errno = %d, message = %s\n", errno, strerror(errno));
        return 1;
    }

    printf("completed successfully\n");

    return 0;
}
