#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main(void) {
    int fd = open("secret.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        printf("errno = %d\n", errno);
        printf("strerror = %s\n", strerror(errno));
        return 1;
    }

    printf("open success\n");

    close(fd);

    return 0;
}
