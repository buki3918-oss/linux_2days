#include <stdio.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child started. PID = %d, PPID = %d\n", getpid(), getppid());
        sleep(10);
        printf("Child finished. PID = %d\n", getpid());
    } else {
        printf("Parent started. PID = %d, child PID = %d\n", getpid(), pid);
        sleep(3);
        printf("Parent finished. PID = %d\n", getpid());
    }

    return 0;
}
