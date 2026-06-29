#include <unistd.h>

int main(void) {
    const char *message = "This message is written to stderr using write().\n";

    write(2, message, 50);

    return 0;
}
