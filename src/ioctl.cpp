#include <sys/ioctl.h>
#include <sys/syscall_wrapper.h>
#include <stdarg.h>

int ioctl(int fd, unsigned long request, ...) {
    va_list args;
    va_start(args, request);
    void* argp = va_arg(args, void*);
    va_end(args);
    
    return syscall(SYS_IOCTL, fd, request, (long)argp, 0, 0, 0);
}