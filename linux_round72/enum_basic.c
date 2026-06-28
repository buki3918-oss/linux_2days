#include <stdio.h>

enum Result {
    PASS,
    FAIL
};

const char *result_to_string(enum Result result) {
    if (result == PASS) {
        return "PASS";
    }

    return "FAIL";
}

int main(void) {
    int score = 75;
    enum Result result;

    if (score >= 60) {
        result = PASS;
    } else {
        result = FAIL;
    }

    printf("score = %d\n", score);
    printf("result = %s\n", result_to_string(result));
    printf("PASS value = %d\n", PASS);
    printf("FAIL value = %d\n", FAIL);

    return 0;
}
