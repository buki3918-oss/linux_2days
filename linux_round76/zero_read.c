#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("/dev/zero", O_RDONLY);

    if (fd == -1) {
        printf("open /dev/zero failed\n");
        return 1;
    }

    unsigned char buffer[16];

    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));

    if (bytes_read == -1) {
        printf("read failed\n");
        close(fd);
        return 1;
    }

    printf("bytes_read = %zd\n", bytes_read);
    printf("data:");

    for (int i = 0; i < bytes_read; i++) {
        printf(" %02x", buffer[i]);
    }

    printf("\n");

    close(fd);

    return 0;
}
