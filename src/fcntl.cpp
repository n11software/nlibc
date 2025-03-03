#include <fcntl.h>
#include <sys/syscall_wrapper.h>
#include <sys/syscall.h>
#include <errno.h>
#include <unistd.h>

int dup(int oldfd) {
    return syscall(SYS_DUP, oldfd, 0, 0, 0, 0, 0);
}

int dup2(int oldfd, int newfd) {
    return syscall(SYS_DUP2, oldfd, newfd, 0, 0, 0, 0);
}

int pipe(int pipefd[2]) {
    return syscall(SYS_PIPE, (long)pipefd, 0, 0, 0, 0, 0);
} 