#include <signal.h>
#include <sys/syscall.h>
#include <sys/syscall_wrapper.h>
#include <errno.h>

int kill(pid_t pid, int sig) {
    return syscall(SYS_KILL, pid, sig, 0, 0, 0, 0);
}

int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact) {
    return syscall(SYS_RT_SIGACTION, signum, (long)act, (long)oldact, sizeof(sigset_t), 0, 0);
}

int sigemptyset(sigset_t *set) {
    if (!set) {
        errno = EINVAL;
        return -1;
    }
    *set = 0;
    return 0;
}

int sigfillset(sigset_t *set) {
    if (!set) {
        errno = EINVAL;
        return -1;
    }
    *set = ~(sigset_t)0;
    return 0;
}

int sigaddset(sigset_t *set, int signum) {
    if (!set || signum < 1 || signum > 32) {
        errno = EINVAL;
        return -1;
    }
    *set |= 1U << (signum - 1);
    return 0;
} 