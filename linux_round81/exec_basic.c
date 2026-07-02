#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Before execl\n");

    execl("/bin/ls", "ls", "-l", NULL);

    printf("After execl\n");

    return 0;
}
