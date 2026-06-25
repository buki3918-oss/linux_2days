#include <stdio.h>
#include <stdlib.h>

void create_memory(void) {
    int *data = malloc(3 * sizeof(int));

    if (data == NULL) {
        printf("malloc failed\n");
        return;
    }

    data[0] = 10;
    data[1] = 20;
    data[2] = 30;

    printf("data[0] = %d\n", data[0]);
    printf("data[1] = %d\n", data[1]);
    printf("data[2] = %d\n", data[2]);

    /*
       Intentionally missing free(data);
       This demonstrates a memory leak.
    */
}

int main(void) {
    create_memory();

    printf("Program finished\n");

    return 0;
}
