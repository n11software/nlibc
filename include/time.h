#pragma once

#include <stddef.h>
#include <sys/types.h>
#include <stddef.h>

typedef int clockid_t;

#define CLOCK_REALTIME  0
#define CLOCK_MONOTONIC 1

typedef unsigned int time_t;

struct tm {
    /*
     * the number of seconds after the minute, normally in the range
     * 0 to 59, but can be up to 60 to allow for leap seconds
     */
    int tm_sec;
    /* the number of minutes after the hour, in the range 0 to 59*/
    int tm_min;
    /* the number of hours past midnight, in the range 0 to 23 */
    int tm_hour;
    /* the day of the month, in the range 1 to 31 */
    int tm_mday;
    /* the number of months since January, in the range 0 to 11 */
    int tm_mon;
    /* the number of years since 1900 */
    long tm_year;
    /* the number of days since Sunday, in the range 0 to 6 */
    int tm_wday;
    /* the number of days since January 1, in the range 0 to 365 */
    int tm_yday;
};

struct timespec {
    time_t tv_sec;
    long tv_nsec;
};

struct itimerval {
    struct timespec it_interval;
    struct timespec it_value;
};

time_t time(time_t* tloc);
int clock_gettime(clockid_t clk_id, struct timespec *tp);
