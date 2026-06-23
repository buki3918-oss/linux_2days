#include <stdio.h>

void change_value(int n) {
    n = 999;
}

void change_by_pointer(int *p) {
    *p = 999;
}

int main(void) {
    int x = 10;
    int y = 10;

    change_value(x);
    change_by_pointer(&y);

    printf("x after change_value = %d\n", x);
    printf("y after change_by_pointer = %d\n", y);

    return 0;
}
