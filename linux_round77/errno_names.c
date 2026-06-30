#include <stdio.h>
#include <errno.h>
#include <string.h>

int main(void) {
    printf("ENOENT = %d, message = %s\n", ENOENT, strerror(ENOENT));
    printf("EACCES = %d, message = %s\n", EACCES, strerror(EACCES));
    printf("EBADF  = %d, message = %s\n", EBADF, strerror(EBADF));
    printf("EINVAL = %d, message = %s\n", EINVAL, strerror(EINVAL));

    return 0;
}
