#include <string.h>
#include <ctype.h>

extern "C" {
    size_t strcspn(const char* str, const char* reject);
}

char* strchr(const char* s, int c) {
    while (*s != (char)c) {
        if (!*s++)
            return NULL;
    }
    return (char*)s;
}

char* strrchr(const char* s, int c) {
    const char* found = NULL;
    while (*s) {
        if (*s == (char)c)
            found = s;
        s++;
    }
    return (char*)found;
}

size_t strspn(const char* s, const char* accept) {
    const char* p;
    const char* a;
    size_t count = 0;

    for (p = s; *p != '\0'; ++p) {
        for (a = accept; *a != '\0'; ++a) {
            if (*p == *a)
                break;
        }
        if (*a == '\0')
            return count;
        ++count;
    }
    return count;
}

char* strtok(char* str, const char* delim) {
    static char* last = NULL;
    
    if (!str) str = last;
    if (!str) return NULL;
    
    // Skip leading delimiters
    str += strspn(str, delim);
    if (*str == '\0') {
        last = NULL;
        return NULL;
    }
    
    // Find end of token
    char* end = str + strcspn(str, delim);
    if (*end == '\0') {
        last = NULL;
        return str;
    }
    
    *end = '\0';
    last = end + 1;
    return str;
} 