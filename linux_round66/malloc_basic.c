#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(sizeof(int));

    if (p == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    *p = 100;

    printf("p address = %p\n", (void *)p);
    printf("*p value = %d\n", *p);

    free(p);

    return 0;
}
