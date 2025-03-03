#include <time.h>
#include <sys/syscall_wrapper.h>
#include <errno.h>

time_t time(time_t* tloc) {
    struct timespec ts;
    if (clock_gettime(CLOCK_REALTIME, &ts) < 0)
        return (time_t)-1;
    
    if (tloc)
        *tloc = ts.tv_sec;
    return ts.tv_sec;
}

int clock_gettime(clockid_t clk_id, struct timespec *tp) {
    return syscall(SYS_CLOCK_GETTIME, clk_id, (long)tp, 0, 0, 0, 0);
}

int nanosleep(const struct timespec *req, struct timespec *rem) {
    return syscall(SYS_NANOSLEEP, (long)req, (long)rem, 0, 0, 0, 0);
}

unsigned int sleep(unsigned int seconds) {
    struct timespec req = {
        .tv_sec = seconds,
        .tv_nsec = 0
    };
    struct timespec rem;
    
    if (nanosleep(&req, &rem) == 0)
        return 0;
    return rem.tv_sec;
} 