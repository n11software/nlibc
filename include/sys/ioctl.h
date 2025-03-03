#pragma once

#include <sys/types.h>

int ioctl(int fd, unsigned long request, ...);

// Terminal ioctls
#define TCGETS      0x5401
#define TCSETS      0x5402
#define TCSETSW     0x5403
#define TCSETSF     0x5404
#define TCGETA      0x5405
#define TCSETA      0x5406
#define TCSETAW     0x5407
#define TCSETAF     0x5408
#define TCSBRK      0x5409
#define TCXONC      0x540A
#define TCFLSH      0x540B
