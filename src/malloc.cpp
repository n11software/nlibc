#include <stdlib.h>
#include <unistd.h>

#define BLOCK_SIZE 4096

extern "C" void* sbrk(intptr_t increment);

void* malloc(size_t size) {
    static void* last_brk = NULL;
    if (!last_brk) last_brk = sbrk(0);

    void* ptr = last_brk;
    last_brk = sbrk(size);
    if (last_brk == (void*)-1) return NULL;

    return ptr;
}

void free(void* ptr) {
    // No-op for now
}
