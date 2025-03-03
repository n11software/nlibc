#pragma once

#include "sys/cdefs.h"
#include "sys/types.h"
#include <stddef.h>

__BEGIN_DECLS

int strlen(const char* str);
int strcmp(const char*, const char*);
char* strcpy(char* dest, const char* src);
int memcmp(const void*, const void*, size_t);
void *memcpy(void *, const void *, size_t);
void* memset(void* str, int c, size_t n);

char* strerror(int errnum);

char *strcat(char *, const char *);

char* strncpy(char* dest, const char* src, size_t n);
int strncmp(const char* s1, const char* s2, size_t n);
char* strchr(const char* s, int c);
char* strrchr(const char* s, int c);
size_t strspn(const char* s, const char* accept);
size_t strcspn(const char* s, const char* reject);

__END_DECLS
