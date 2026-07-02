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
        printf("Child: trying to execute missing command\n");

        execl("/bin/not_exist_command", "not_exist_command", NULL);

        perror("execl");
        return 2;
    } else {
        int status;

        printf("Parent: waiting for child PID = %d\n", pid);

        wait(&status);

        if (WIFEXITED(status)) {
            printf("Parent: child exit code = %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent: child did not exit normally\n");
        }
    }

    return 0;
}
