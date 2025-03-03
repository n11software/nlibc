#include <fcntl.h>
#include <signal.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

static inline long syscall(long num, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6)
{
    long ret;
    asm volatile(
        "syscall"
        : "=a"(ret)
        : "r"(num), "r"(arg1), "r"(arg2), "r"(arg3), "r"(arg4), "r"(arg5), "r"(arg6)
        : "rcx", "r11", "memory"
    );
    return ret;
}




int open(const char *pathname, int flags, mode_t mode)
{
    return (int)syscall(SYS_OPEN, (long)pathname, flags, mode, 0, 0, 0);
}

ssize_t read(int fd, void *buf, size_t count)
{
    return (ssize_t)syscall(SYS_READ, fd, (long)buf, count, 0, 0, 0);
}

ssize_t write(int fd, const void *buf, size_t count)
{
    return (ssize_t)syscall(SYS_WRITE, fd, (long)buf, count, 0, 0, 0);
}

int close(int fd)
{
    return (int)syscall(SYS_CLOSE, fd, 0, 0, 0, 0, 0);
}

void *malloc(size_t size)
{
    // Memory allocation using sbrk (no standard system call for malloc)
    static void *brk = NULL;
    if (!brk) brk = (void *)syscall(SYS_BRK, 0, 0, 0, 0, 0, 0);

    void *ptr = brk;
    brk = (void *)syscall(SYS_BRK, (long)(brk) + size, 0, 0, 0, 0, 0);
    if (brk == (void *)-1) return NULL;
    return ptr;
}

void free(void *ptr)
{
    // A simple no-op, as free() isn't implemented in this context
    // You'd need a more complex memory manager for real "free" functionality
}

pid_t fork(void)
{
    return syscall(SYS_FORK, 0, 0, 0, 0, 0, 0);
}

int execve(const char *filename, char *const argv[], char *const envp[])
{
    return syscall(SYS_EXECVE, (long)filename, (long)argv, (long)envp, 0, 0, 0);
}

pid_t wait(int *status)
{
    return syscall(SYS_WAIT4, -1, (long)status, 0, 0, 0, 0);
}
