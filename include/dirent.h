#pragma once

#include <sys/types.h>

struct dirent {
    ino_t d_ino;           /* Inode number */
    off_t d_off;           /* Offset to next dirent */
    unsigned short d_reclen;/* Length of this record */
    unsigned char d_type;   /* Type of file */
    char d_name[256];      /* Filename */
};

typedef struct DIR DIR;

DIR* opendir(const char* name);
struct dirent* readdir(DIR* dir);
int closedir(DIR* dir);

/* File types for d_type */
#define DT_UNKNOWN  0
#define DT_FIFO     1
#define DT_CHR      2
#define DT_DIR      4
#define DT_BLK      6
#define DT_REG      8
#define DT_LNK      10
#define DT_SOCK     12 