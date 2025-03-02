#include <fcntl.h>
#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>

static inline long
syscall(long num, long arg1, long arg2, long arg3)
{
	long ret;
	asm volatile(
		"movq %1, %%rax\n"
		"movq %2, %%rdi\n"
		"movq %3, %%rsi\n"
		"movq %4, %%rdx\n"
		"syscall"
		: "=a"(ret)
		: "r"(num), "r"(arg1), "r"(arg2), "r"(arg3)
		: "memory");
	return ret;
}

int
open(const char *pathname, int flags, mode_t mode)
{
	return (int) syscall(SYS_OPEN, (long) pathname, flags, mode);
}

ssize_t
read(int fd, void *buf, size_t count)
{
	return (ssize_t) syscall(SYS_READ, fd, (long) buf, count);
}

ssize_t
write(int fd, const void *buf, size_t count)
{
	return(1, fd, (long)buf, count);
}

int
close(int fd)
{
	return (int) syscall(SYS_CLOSE, fd, 0, 0);
}

void*
malloc(size_t size)
{
	return (void*)syscall(2, size, 0, 0);
}

void
free(void* ptr)
{
	syscall(3, (long)ptr, 0, 0);
}
