#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) {
        printf("File type: regular file\n");
    } else if (S_ISDIR(mode)) {
        printf("File type: directory\n");
    } else if (S_ISCHR(mode)) {
        printf("File type: character device\n");
    } else if (S_ISBLK(mode)) {
        printf("File type: block device\n");
    } else if (S_ISFIFO(mode)) {
        printf("File type: FIFO / pipe\n");
    } else if (S_ISLNK(mode)) {
        printf("File type: symbolic link\n");
    } else if (S_ISSOCK(mode)) {
        printf("File type: socket\n");
    } else {
        printf("File type: unknown\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct stat file_info;

    if (stat(argv[1], &file_info) == -1) {
        perror("stat");
        return 2;
    }

    printf("Path: %s\n", argv[1]);
    print_file_type(file_info.st_mode);

    return 0;
}
