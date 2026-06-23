#include <stdio.h>

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};

    printf("Array values using arr[i]:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\nArray values using *(arr + i):\n");
    for (int i = 0; i < 5; i++) {
        printf("*(arr + %d) = %d\n", i, *(arr + i));
    }

    printf("\nArray addresses:\n");
    for (int i = 0; i < 5; i++) {
        printf("&arr[%d] = %p\n", i, (void *)&arr[i]);
    }

    printf("\nPointer-style addresses:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr + %d = %p\n", i, (void *)(arr + i));
    }

    printf("\nImportant comparison:\n");
    printf("arr = %p\n", (void *)arr);
    printf("&arr[0] = %p\n", (void *)&arr[0]);

    return 0;
}
