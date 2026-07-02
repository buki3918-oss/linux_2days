#include <stdio.h>
#include <unistd.h>

int main(void) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Child: about to exec ls\n");
        execl("/bin/ls", "ls", "-l", NULL);

        perror("execl");
        return 2;
    } else {
        printf("Parent: created child PID = %d\n", pid);
        printf("Parent: not waiting yet\n");
    }

    return 0;
}
