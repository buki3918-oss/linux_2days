#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    int score;
};

int main(void) {
    struct Student s1;

    s1.id = 1;
    strcpy(s1.name, "Sunny");
    s1.score = 90;

    printf("Student Information:\n");
    printf("id = %d\n", s1.id);
    printf("name = %s\n", s1.name);
    printf("score = %d\n", s1.score);

    printf("\nAddresses:\n");
    printf("&s1 = %p\n", (void *)&s1);
    printf("&s1.id = %p\n", (void *)&s1.id);
    printf("&s1.name = %p\n", (void *)&s1.name);
    printf("&s1.score = %p\n", (void *)&s1.score);

    printf("\nSize:\n");
    printf("sizeof(s1) = %zu\n", sizeof(s1));

    return 0;
}
