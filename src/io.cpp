#include <unistd.h> // for syscalls

int getchar(void) {
    char c;
    ssize_t res = read(STDIN_FILENO, &c, 1);  // Read a single byte from stdin
    if (res < 0) return -1;  // Error
    return c;
}

int putchar(int c) {
    ssize_t res = write(STDOUT_FILENO, &c, 1);  // Write a single byte to stdout
    return (res < 0) ? -1 : c;
}
