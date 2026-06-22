#include <stdio.h>

int global_counter = 100;

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

void print_result(const char *label, int value) {
    printf("%s = %d\n", label, value);
}

int main(void) {
    int x = 7;
    int y = 5;

    int sum = add(x, y);
    int product = multiply(x, y);

    print_result("sum", sum);
    print_result("product", product);
    print_result("global_counter", global_counter);

    return 0;
}
