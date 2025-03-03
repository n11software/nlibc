#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <sys/syscall.h>
#include <sys/syscall_wrapper.h>

extern "C" {
    int strlen(const char* s);
}

int vsprintf(char* str, const char* format, va_list ap) {
    char* str_ptr = str;
    const char* fmt_ptr = format;
    
    while (*fmt_ptr) {
        if (*fmt_ptr != '%') {
            *str_ptr++ = *fmt_ptr++;
            continue;
        }
        
        fmt_ptr++;
        switch (*fmt_ptr) {
            case 's': {
                const char* s = va_arg(ap, const char*);
                while (*s) *str_ptr++ = *s++;
                break;
            }
            case 'd': {
                int num = va_arg(ap, int);
                if (num < 0) {
                    *str_ptr++ = '-';
                    num = -num;
                }
                char num_buf[32];
                int i = 0;
                do {
                    num_buf[i++] = '0' + (num % 10);
                    num /= 10;
                } while (num);
                while (i--) *str_ptr++ = num_buf[i];
                break;
            }
        }
        fmt_ptr++;
    }
    *str_ptr = '\0';
    return str_ptr - str;
}

int fprintf(FILE* stream, const char* format, ...) {
    char buf[1024];
    va_list args;
    va_start(args, format);
    int ret = vsprintf(buf, format, args);
    va_end(args);
    
    if (ret < 0) return ret;
    return syscall(SYS_WRITE, stream->fd, (long)buf, strlen(buf), 0, 0, 0);
}

int sprintf(char* str, const char* format, ...) {
    va_list args;
    va_start(args, format);
    int ret = vsprintf(str, format, args);
    va_end(args);
    return ret;
} 