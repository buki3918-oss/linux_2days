#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Before fork\n");

    pid_t pid = fork();

    printf("After fork\n");

    return 0;
}
