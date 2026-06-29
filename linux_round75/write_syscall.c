#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("syscall_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        printf("open failed\n");
        return 1;
    }

    const char *message = "Hello from Linux system call write()!\n";

    ssize_t bytes_written = write(fd, message, 39);

    if (bytes_written == -1) {
        printf("write failed\n");
        close(fd);
        return 1;
    }

    printf("bytes_written = %zd\n", bytes_written);

    close(fd);

    return 0;
}
