#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child: PID = %d, sleeping 3 seconds\n", getpid());
        sleep(3);
        printf("Child: finished\n");
        return 7;
    } else {
        int status;

        printf("Parent: waiting for child PID = %d\n", pid);

        pid_t finished_pid = wait(&status);

        printf("Parent: child finished, wait returned PID = %d\n", finished_pid);
        printf("Parent: raw status = %d\n", status);
    }

    return 0;
}
