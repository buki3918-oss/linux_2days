#include <stdio.h>

int add(int a, int b) {
    int result = a + b;
    return result;
}

int multiply(int a, int b) {
    int result = a * b;
    return result;
}

int calculate_score(int base, int bonus) {
    int total = add(base, bonus);
    int final_score = multiply(total, 2);
    return final_score;
}

int main(void) {
    int base = 60;
    int bonus = 15;
    int score = calculate_score(base, bonus);

    printf("base = %d\n", base);
    printf("bonus = %d\n", bonus);
    printf("score = %d\n", score);

    return 0;
}
