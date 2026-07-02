#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Start PID = %d\n", getpid());

    fork();
    fork();

    printf("Hello from PID = %d, PPID = %d\n", getpid(), getppid());

    return 0;
}
