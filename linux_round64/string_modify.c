#include <stdio.h>

int main(void) {
    char name[] = "Sunny";

    printf("Before: %s\n", name);

    name[0] = 'F';
    name[1] = 'u';
    name[2] = 'n';

    printf("After: %s\n", name);

    return 0;
}
