#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    int score;
};

void print_student(struct Student *s) {
    printf("id = %d\n", s->id);
    printf("name = %s\n", s->name);
    printf("score = %d\n", s->score);
}

void update_score(struct Student *s, int new_score) {
    s->score = new_score;
}

int main(void) {
    struct Student s1;

    s1.id = 2;
    strcpy(s1.name, "Yichieh");
    s1.score = 85;

    printf("Before update:\n");
    print_student(&s1);

    update_score(&s1, 95);

    printf("\nAfter update:\n");
    print_student(&s1);

    return 0;
}
