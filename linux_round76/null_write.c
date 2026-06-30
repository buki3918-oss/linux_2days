#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("/dev/null", O_WRONLY);

    if (fd == -1) {
        printf("open /dev/null failed\n");
        return 1;
    }

    const char *message = "This message goes to /dev/null.\n";

    ssize_t bytes_written = write(fd, message, 33);

    if (bytes_written == -1) {
        printf("write failed\n");
        close(fd);
        return 1;
    }

    printf("bytes_written = %zd\n", bytes_written);
    printf("The message was written, but discarded by /dev/null.\n");

    close(fd);

    return 0;
}
