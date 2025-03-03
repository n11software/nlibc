#pragma once

#include <sys/cdefs.h>
#include <stddef.h>

__BEGIN_DECLS

void* malloc(size_t size);
void free(void* ptr);

void exit(int status);

__END_DECLS
