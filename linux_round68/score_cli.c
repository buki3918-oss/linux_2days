#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <name> <score>\n", argv[0]);
        return 1;
    }

    char *name = argv[1];
    int score = atoi(argv[2]);

    printf("name = %s\n", name);
    printf("score = %d\n", score);

    if (score >= 60) {
        printf("result = pass\n");
    } else {
        printf("result = fail\n");
    }

    return 0;
}
