#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_file> <dest_file>\n", argv[0]);
        return 1;
    }

    int src_fd = open(argv[1], O_RDONLY);

    if (src_fd == -1) {
        printf("failed to open source file\n");
        return 2;
    }

    int dest_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (dest_fd == -1) {
        printf("failed to open destination file\n");
        close(src_fd);
        return 3;
    }

    char buffer[64];
    ssize_t bytes_read;

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        ssize_t bytes_written = write(dest_fd, buffer, bytes_read);

        if (bytes_written == -1) {
            printf("write failed\n");
            close(src_fd);
            close(dest_fd);
            return 4;
        }
    }

    if (bytes_read == -1) {
        printf("read failed\n");
        close(src_fd);
        close(dest_fd);
        return 5;
    }

    close(src_fd);
    close(dest_fd);

    printf("File copied successfully\n");

    return 0;
}
