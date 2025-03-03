#include <signal.h>
#include <sys/syscall.h>

sighandler_t signal(int signum, sighandler_t handler) {
    // Basic signal implementation - you'll need to add SYS_SIGNAL to syscall.h
    struct sigaction sa, old_sa;
    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    if (sigaction(signum, &sa, &old_sa) < 0)
        return SIG_ERR;
        
    return old_sa.sa_handler;
} 