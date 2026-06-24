#include <stdio.h>
#include <string.h>

int main(void) {
    char word[] = "Hi";

    printf("word = %s\n", word);
    printf("strlen(word) = %zu\n", strlen(word));
    printf("sizeof(word) = %zu\n", sizeof(word));

    printf("\nCharacters and ASCII codes:\n");
    for (int i = 0; i < 3; i++) {
        printf("word[%d] = '%c', ASCII = %d, address = %p\n",
               i, word[i], word[i], (void *)&word[i]);
    }

    if (word[2] == '\0') {
        printf("\nword[2] is null terminator '\\0'\n");
    }

    return 0;
}
