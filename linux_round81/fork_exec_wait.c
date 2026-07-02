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
        printf("Child: executing /bin/ls\n");

        execl("/bin/ls", "ls", "-l", NULL);

        perror("execl");
        return 2;
    } else {
        int status;

        printf("Parent: waiting for child PID = %d\n", pid);

        pid_t finished_pid = wait(&status);

        printf("Parent: child finished, PID = %d\n", finished_pid);

        if (WIFEXITED(status)) {
            printf("Parent: child exit code = %d\n", WEXITSTATUS(status));
        } else {
            printf("Parent: child did not exit normally\n");
        }
    }

    return 0;
}
