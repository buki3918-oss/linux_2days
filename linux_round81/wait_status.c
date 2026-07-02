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
        printf("Child: exiting with code 7\n");
        return 7;
    } else {
        int status;

        printf("Parent: waiting for child\n");

        wait(&status);

        if (WIFEXITED(status)) {
            printf("Parent: child exited normally\n");
            printf("Parent: child exit code = %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent: child did not exit normally\n");
        }
    }

    return 0;
}
