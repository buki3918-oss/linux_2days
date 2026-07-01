#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void) {
    struct stat file_info;

    if (stat("sample.txt", &file_info) == -1) {
        perror("stat");
        return 1;
    }

    printf("File: sample.txt\n");
    printf("Size: %ld bytes\n", file_info.st_size);
    printf("UID: %d\n", file_info.st_uid);
    printf("GID: %d\n", file_info.st_gid);
    printf("Mode: %o\n", file_info.st_mode);

    return 0;
}
