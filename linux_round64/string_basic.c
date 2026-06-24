#include <stdio.h>
#include <string.h>

int main(void) {
    char name1[] = "Sunny";
    char *name2 = "Yichieh";

    printf("name1 = %s\n", name1);
    printf("name2 = %s\n", name2);

    printf("strlen(name1) = %zu\n", strlen(name1));
    printf("strlen(name2) = %zu\n", strlen(name2));

    printf("sizeof(name1) = %zu\n", sizeof(name1));
    printf("sizeof(name2) = %zu\n", sizeof(name2));

    return 0;
}
