#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) {
        printf("Type: regular file\n");
    } else if (S_ISDIR(mode)) {
        printf("Type: directory\n");
    } else if (S_ISCHR(mode)) {
        printf("Type: character device\n");
    } else if (S_ISBLK(mode)) {
        printf("Type: block device\n");
    } else if (S_ISFIFO(mode)) {
        printf("Type: FIFO / pipe\n");
    } else if (S_ISLNK(mode)) {
        printf("Type: symbolic link\n");
    } else if (S_ISSOCK(mode)) {
        printf("Type: socket\n");
    } else {
        printf("Type: unknown\n");
    }
}

void print_permissions(mode_t mode) {
    printf("Permissions: ");

    printf("%c", (mode & S_IRUSR) ? 'r' : '-');
    printf("%c", (mode & S_IWUSR) ? 'w' : '-');
    printf("%c", (mode & S_IXUSR) ? 'x' : '-');

    printf("%c", (mode & S_IRGRP) ? 'r' : '-');
    printf("%c", (mode & S_IWGRP) ? 'w' : '-');
    printf("%c", (mode & S_IXGRP) ? 'x' : '-');

    printf("%c", (mode & S_IROTH) ? 'r' : '-');
    printf("%c", (mode & S_IWOTH) ? 'w' : '-');
    printf("%c\n", (mode & S_IXOTH) ? 'x' : '-');
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    struct stat file_info;

    if (stat(argv[1], &file_info) == -1) {
        perror("stat");
        return 2;
    }

    printf("Path: %s\n", argv[1]);
    print_file_type(file_info.st_mode);

    printf("Size: %ld bytes\n", file_info.st_size);
    printf("UID: %d\n", file_info.st_uid);
    printf("GID: %d\n", file_info.st_gid);
    printf("Permission bits: %o\n", file_info.st_mode & 0777);
    print_permissions(file_info.st_mode);

    printf("Access time: %s", ctime(&file_info.st_atime));
    printf("Modify time: %s", ctime(&file_info.st_mtime));
    printf("Change time: %s", ctime(&file_info.st_ctime));

    return 0;
}
