#include <unistd.h>
#include <sys/syscall_wrapper.h>
#include <sys/syscall.h>

pid_t getpgrp(void) {
    return syscall(SYS_GETPGRP, 0, 0, 0, 0, 0, 0);
}

pid_t getpgid(pid_t pid) {
    return syscall(SYS_GETPGID, pid, 0, 0, 0, 0, 0);
}

int setpgid(pid_t pid, pid_t pgid) {
    return syscall(SYS_SETPGID, pid, pgid, 0, 0, 0, 0);
}

pid_t setsid(void) {
    return syscall(SYS_SETSID, 0, 0, 0, 0, 0, 0);
}

pid_t getsid(pid_t pid) {
    return syscall(SYS_GETSID, pid, 0, 0, 0, 0, 0);
} 