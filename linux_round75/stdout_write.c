#include <unistd.h>

int main(void) {
    const char *message = "This message is written to stdout using write().\n";

    write(1, message, 50);

    return 0;
}
