#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size = 3;

    int *arr = malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = (i + 1) * 10;
    }

    printf("Before realloc:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d, address = %p\n", i, arr[i], (void *)&arr[i]);
    }

    int new_size = 6;

    int *new_arr = realloc(arr, new_size * sizeof(int));

    if (new_arr == NULL) {
        printf("realloc failed\n");
        free(arr);
        return 1;
    }

    arr = new_arr;

    for (int i = size; i < new_size; i++) {
        arr[i] = (i + 1) * 10;
    }

    printf("\nAfter realloc:\n");
    for (int i = 0; i < new_size; i++) {
        printf("arr[%d] = %d, address = %p\n", i, arr[i], (void *)&arr[i]);
    }

    free(arr);

    return 0;
}
