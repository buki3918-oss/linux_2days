#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;

    printf("x value = %d\n", x);
    printf("x address = %p\n", (void *)&x);

    printf("p value = %p\n", (void *)p);
    printf("p address = %p\n", (void *)&p);
    printf("*p value = %d\n", *p);

    *p = 20;

    printf("After *p = 20:\n");
    printf("x value = %d\n", x);
    printf("*p value = %d\n", *p);

    return 0;
}
