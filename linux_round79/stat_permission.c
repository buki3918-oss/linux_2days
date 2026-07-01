#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

void print_permissions(mode_t mode) {
    printf("Owner: ");
    printf("%c", (mode & S_IRUSR) ? 'r' : '-');
    printf("%c", (mode & S_IWUSR) ? 'w' : '-');
    printf("%c\n", (mode & S_IXUSR) ? 'x' : '-');

    printf("Group: ");
    printf("%c", (mode & S_IRGRP) ? 'r' : '-');
    printf("%c", (mode & S_IWGRP) ? 'w' : '-');
    printf("%c\n", (mode & S_IXGRP) ? 'x' : '-');

    printf("Others: ");
    printf("%c", (mode & S_IROTH) ? 'r' : '-');
    printf("%c", (mode & S_IWOTH) ? 'w' : '-');
    printf("%c\n", (mode & S_IXOTH) ? 'x' : '-');
}

int main(void) {
    struct stat file_info;

    if (stat("sample.txt", &file_info) == -1) {
        perror("stat");
        return 1;
    }

    printf("File: sample.txt\n");
    printf("Permission bits: %o\n", file_info.st_mode & 0777);

    print_permissions(file_info.st_mode);

    return 0;
}
