#include <stdio.h>
#include <stdlib.h>

extern "C" void initialize_standard_library() {
    // Initialize standard input, output, and error streams
    stdin = fopen("/dev/stdin", "r");
    stdout = fopen("/dev/stdout", "w");
    stderr = fopen("/dev/stderr", "w");
}
