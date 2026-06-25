#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int size;

    printf("Enter array size: ");
    scanf("%d", &size);

    if (size <= 0) {
        printf("size must be positive\n");
        return 1;
    }

    int *arr = malloc(size * sizeof(int));

    if (arr == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }

    printf("Array values:\n");
    for (int i = 0; i < size; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);

    return 0;
}
