#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 5;
    int *arr = malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;
    }

    printf("Dynamic array values:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d, address = %p\n", i, arr[i], (void *)&arr[i]);
    }

    printf("\nImportant:\n");
    printf("arr = %p\n", (void *)arr);
    printf("&arr[0] = %p\n", (void *)&arr[0]);
    printf("sizeof(arr) = %zu\n", sizeof(arr));
    printf("sizeof(arr[0]) = %zu\n", sizeof(arr[0]));

    free(arr);

    return 0;
}
