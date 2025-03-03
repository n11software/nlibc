#include <unistd.h>
#include <sys/syscall_wrapper.h>
#include <errno.h>

pid_t fork(void) {
    return syscall(SYS_FORK, 0, 0, 0, 0, 0, 0);
}

int execve(const char *pathname, char *const argv[], char *const envp[]) {
    return syscall(SYS_EXECVE, (long)pathname, (long)argv, (long)envp, 0, 0, 0);
}

pid_t waitpid(pid_t pid, int *status, int options) {
    return syscall(SYS_WAIT4, pid, (long)status, options, 0, 0, 0);
}

int chdir(const char *path) {
    // Add syscall number for chdir in syscall.h first
    return syscall(SYS_CHDIR, (long)path, 0, 0, 0, 0, 0);
} 