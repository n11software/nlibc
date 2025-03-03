#include <termios.h>
#include <sys/syscall_wrapper.h>
#include <errno.h>
#include <sys/ioctl.h>
int tcgetattr(int fd, struct termios *termios_p) {
    return syscall(SYS_IOCTL, fd, TCGETS, (long)termios_p, 0, 0, 0);
}

int tcsetattr(int fd, int optional_actions, const struct termios *termios_p) {
    int cmd;
    switch (optional_actions) {
        case TCSANOW:   cmd = TCSETS;   break;
        case TCSADRAIN: cmd = TCSETSW;  break;
        case TCSAFLUSH: cmd = TCSETSF;  break;
        default:
            errno = EINVAL;
            return -1;
    }
    return syscall(SYS_IOCTL, fd, cmd, (long)termios_p, 0, 0, 0);
}

int tcflow(int fd, int action) {
    return syscall(SYS_IOCTL, fd, TCXONC, action, 0, 0, 0);
}

int tcflush(int fd, int queue_selector) {
    return syscall(SYS_IOCTL, fd, TCFLSH, queue_selector, 0, 0, 0);
} 