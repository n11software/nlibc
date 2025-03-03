#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/syscall_wrapper.h>

extern "C" {
    int strncmp(const char* s1, const char* s2, size_t n);
    char* strchr(const char* s, int c);
}

char** environ = NULL;

char* getenv(const char* name) {
    if (!environ) return NULL;
    
    size_t len = strlen(name);
    for (char** env = environ; *env != NULL; env++) {
        if (strncmp(*env, name, len) == 0 && (*env)[len] == '=') {
            return &(*env)[len + 1];
        }
    }
    return NULL;
}

int setenv(const char* name, const char* value, int overwrite) {
    if (!name || !value || strchr(name, '=')) {
        errno = EINVAL;
        return -1;
    }

    size_t len = strlen(name);
    char* existing = getenv(name);
    
    if (existing && !overwrite)
        return 0;

    size_t value_len = strlen(value);
    char* new_var = (char*)malloc(len + value_len + 2);
    if (!new_var) {
        errno = ENOMEM;
        return -1;
    }

    strcpy(new_var, name);
    new_var[len] = '=';
    strcpy(new_var + len + 1, value);
    
    // TODO: Add to environ array
    return 0;
} 