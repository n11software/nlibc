#pragma once

#include <stddef.h>

struct timeval {
    unsigned int     tv_sec;     /* seconds */
    long tv_usec;    /* microseconds */
};

struct timezone {
    int tz_minuteswest;     /* minutes west of Greenwich */
    int tz_dsttime;         /* type of DST correction */
};

int gettimeofday(struct timeval *tv, void *tz); 