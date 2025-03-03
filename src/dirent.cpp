#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/syscall_wrapper.h>
#include <fcntl.h>
#include <unistd.h>

struct DIR {
    int fd;
    struct dirent current;
};

DIR* opendir(const char* name) {
    int fd = syscall(SYS_OPEN, (long)name, O_RDONLY | O_DIRECTORY, 0, 0, 0, 0);
    if (fd < 0) {
        errno = -fd;
        return NULL;
    }
        
    DIR* dir = (DIR*)malloc(sizeof(DIR));
    if (!dir) {
        syscall(SYS_CLOSE, fd, 0, 0, 0, 0, 0);
        errno = ENOMEM;
        return NULL;
    }
    
    dir->fd = fd;
    return dir;
}

struct dirent* readdir(DIR* dir) {
    if (!dir) {
        errno = EBADF;
        return NULL;
    }

    int ret = syscall(SYS_GETDENTS, dir->fd, (long)&dir->current, sizeof(struct dirent), 0, 0, 0);
    if (ret <= 0)
        return NULL;
        
    return &dir->current;
}

int closedir(DIR* dir) {
    if (!dir) {
        errno = EBADF;
        return -1;
    }
    
    int fd = dir->fd;
    free(dir);
    return syscall(SYS_CLOSE, fd, 0, 0, 0, 0, 0);
}

extern "C" {
} // extern "C" 