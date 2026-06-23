#include <stdio.h>

int main(void) {
    int arr[5] = {5, 10, 15, 20, 25};
    int *p = arr;

    printf("Walk array using pointer:\n");

    for (int i = 0; i < 5; i++) {
        printf("i = %d, p = %p, *p = %d\n", i, (void *)p, *p);
        p++;
    }

    return 0;
}
