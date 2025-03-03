#include <sys/stat.h>
#include <sys/syscall_wrapper.h>
#include <errno.h>

int stat(const char *path, struct stat *buf) {
    return syscall(SYS_STAT, (long)path, (long)buf, 0, 0, 0, 0);
}

int fstat(int fd, struct stat *buf) {
    return syscall(SYS_FSTAT, fd, (long)buf, 0, 0, 0, 0);
}

int lstat(const char *path, struct stat *buf) {
    return syscall(SYS_LSTAT, (long)path, (long)buf, 0, 0, 0, 0);
}

int chmod(const char *path, mode_t mode) {
    return syscall(SYS_CHMOD, (long)path, mode, 0, 0, 0, 0);
}

int fchmod(int fd, mode_t mode) {
    return syscall(SYS_FCHMOD, fd, mode, 0, 0, 0, 0);
} 