#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Before fork: current PID = %d\n", getpid());

    pid_t pid = fork();

    printf("After fork: fork return value = %d, current PID = %d, parent PID = %d\n",
           pid, getpid(), getppid());

    return 0;
}
