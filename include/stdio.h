#pragma once

#include <sys/cdefs.h>

__BEGIN_DECLS

#define EOF (-1)

struct __STDIO_FILE {
    int fd;
};

typedef struct __STDIO_FILE FILE;

extern FILE* stdin;
extern FILE* stdout;
extern FILE* stderr;

int fprintf(FILE*, const char* fmt, ...);
int printf(const char* fmt, ...);
int sprintf(char* buffer, const char* fmt, ...);
int putchar(int ch);
void perror(const char*);

FILE* fopen(const char* filename, const char* mode);
int fgetc(FILE* stream);
int fclose(FILE* stream);

#ifndef SEEK_SET
#define	SEEK_SET	0	/* set file offset to offset */
#endif
#ifndef SEEK_CUR
#define	SEEK_CUR	1	/* set file offset to current plus offset */
#endif
#ifndef SEEK_END
#define	SEEK_END	2	/* set file offset to EOF plus offset */
#endif

__END_DECLS
