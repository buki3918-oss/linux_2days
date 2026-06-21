#include <stdio.h>
#include "math_utils.h"

int main(void) {
    int a = 6;
    int b = 4;

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("add(a, b) = %d\n", add(a, b));
    printf("multiply(a, b) = %d\n", multiply(a, b));

    return 0;
}
