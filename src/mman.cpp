#include <sys/mman.h>
#include <sys/syscall_wrapper.h>
#include <errno.h>

void* mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
    long ret = syscall(SYS_MMAP, (long)addr, length, prot, flags, fd, offset);
    if (ret < 0 && ret > -4096) {
        errno = -ret;
        return MAP_FAILED;
    }
    return (void*)ret;
}

int munmap(void *addr, size_t length) {
    return syscall(SYS_MUNMAP, (long)addr, length, 0, 0, 0, 0);
}

int mprotect(void *addr, size_t len, int prot) {
    return syscall(SYS_MPROTECT, (long)addr, len, prot, 0, 0, 0);
} 