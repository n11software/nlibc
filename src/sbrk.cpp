#include <unistd.h>
#include <errno.h>

extern "C" {
    static void* program_break = nullptr;

    void* sbrk(intptr_t increment) {
        if (program_break == nullptr) {
            program_break = (void*)0x100000;  // Set initial break to 1MB
        }

        void* old_break = program_break;
        void* new_break = (char*)program_break + increment;

        if (new_break < (void*)0x100000 || new_break >= (void*)0x80000000) {
            errno = ENOMEM;
            return (void*)-1;
        }

        program_break = new_break;
        return old_break;
    }
}
