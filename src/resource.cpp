#include <sys/resource.h>
#include <sys/syscall_wrapper.h>
#include <errno.h>

int getrlimit(int resource, struct rlimit *rlim) {
    return syscall(SYS_GETRLIMIT, resource, (long)rlim, 0, 0, 0, 0);
}

int setrlimit(int resource, const struct rlimit *rlim) {
    return syscall(SYS_SETRLIMIT, resource, (long)rlim, 0, 0, 0, 0);
}

int getrusage(int who, struct rusage *usage) {
    return syscall(SYS_GETRUSAGE, who, (long)usage, 0, 0, 0, 0);
} 