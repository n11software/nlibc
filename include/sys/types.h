#pragma once

#include <stddef.h>
#include <sys/time.h>

#ifndef _SYS_TYPES_H
#define _SYS_TYPES_H

typedef unsigned char   u_char;
typedef unsigned short  u_short;
typedef unsigned int   blksize_t;
typedef unsigned int   blkcnt_t;

typedef int            pid_t;
typedef unsigned int   uid_t;
typedef unsigned int   gid_t;
typedef unsigned int   mode_t;
typedef unsigned int   ino_t;
typedef long           off_t;
typedef unsigned int   dev_t;
typedef unsigned int   nlink_t;

#endif /* _SYS_TYPES_H */
