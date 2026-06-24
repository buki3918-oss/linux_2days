#include <stdio.h>

int main(void) {
    char text[] = "ABC";
    char *p = text;

    printf("Walk string using char pointer:\n");

    while (*p != '\0') {
        printf("p = %p, *p = '%c'\n", (void *)p, *p);
        p++;
    }

    printf("p = %p, *p = '\\0' reached\n", (void *)p);

    return 0;
}
