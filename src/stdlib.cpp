#include <stdlib.h>
#include <unistd.h>

extern "C" void _exit(int status) {
    _exit(status);
}

void exit(int status) {
    _exit(status);
}
