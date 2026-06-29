#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("syscall_output.txt", O_RDONLY);

    if (fd == -1) {
        printf("open failed\n");
        return 1;
    }

    char buffer[128];

    ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);

    if (bytes_read == -1) {
        printf("read failed\n");
        close(fd);
        return 1;
    }

    buffer[bytes_read] = '\0';

    printf("bytes_read = %zd\n", bytes_read);
    printf("content:\n%s", buffer);

    close(fd);

    return 0;
}
