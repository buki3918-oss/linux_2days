#include <stdio.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child process\n");
        printf("Child PID = %d\n", getpid());
        printf("Child PPID = %d\n", getppid());
    } else {
        printf("Parent process\n");
        printf("Parent PID = %d\n", getpid());
        printf("Created child PID = %d\n", pid);
    }

    return 0;
}
