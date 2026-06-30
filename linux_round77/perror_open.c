#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void) {
    int fd = open("missing_file.txt", O_RDONLY);

    if (fd == -1) {
        perror("open");
        return 1;
    }

    close(fd);

    return 0;
}
