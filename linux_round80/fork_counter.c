#include <stdio.h>
#include <unistd.h>

int main(void) {
    int counter = 100;

    printf("Before fork: counter = %d, PID = %d\n", counter, getpid());

    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        counter += 10;
        printf("Child: counter = %d, PID = %d\n", counter, getpid());
    } else {
        counter += 20;
        printf("Parent: counter = %d, PID = %d, child PID = %d\n", counter, getpid(), pid);
    }

    return 0;
}
