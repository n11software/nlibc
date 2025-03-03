#include <stdio.h>
#include <fcntl.h>  // Include for O_* constants
#include <unistd.h>  // Include for close, read, open
#include <stdlib.h>
#include <errno.h>

FILE* stdin = nullptr;
FILE* stdout = nullptr;
FILE* stderr = nullptr;

FILE* fopen(const char* filename, const char* mode) {
    int flags = 0;

    if (mode[0] == 'r') {
        flags = O_RDONLY;
    } else if (mode[0] == 'w') {
        flags = O_WRONLY | O_CREAT | O_TRUNC;
    } else if (mode[0] == 'a') {
        flags = O_WRONLY | O_CREAT | O_APPEND;
    } else {
        errno = EINVAL;
        return NULL;
    }

    int fd = open(filename, flags, 0644);
    if (fd < 0) {
        return NULL;
    }

    FILE* file = (FILE*)malloc(sizeof(FILE));
    if (!file) {
        close(fd);
        errno = ENOMEM;
        return NULL;
    }

    file->fd = fd;
    return file;
}

int fgetc(FILE* stream) {
    unsigned char c;
    if (read(stream->fd, &c, 1) == 1) {
        return c;
    } else {
        return EOF;
    }
}

int fclose(FILE* stream) {
    if (!stream) {
        errno = EINVAL;
        return EOF;
    }

    int result = close(stream->fd);
    free(stream);

    return result;
}

int putchar(int ch) {
    return write(STDOUT_FILENO, &ch, 1) == 1 ? ch : EOF;
}
