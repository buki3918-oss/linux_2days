#include <stdio.h>
#include <unistd.h>

int main(void) {
    printf("Before execl\n");

    execl("/bin/not_exist_command", "not_exist_command", NULL);

    perror("execl");
    printf("After failed execl\n");

    return 1;
}
