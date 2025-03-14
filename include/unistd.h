#pragma once

#include <stddef.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#include <stddef.h>
#include <stdint.h>

__BEGIN_DECLS

uid_t getuid();
gid_t getgid();
pid_t getpid();

pid_t waitpid(pid_t, int* wstatus, int options);
int chdir(const char* path);
char* getcwd(char* buffer, size_t size);
int lstat(const char* path, struct stat* statbuf);
int sleep(unsigned seconds);
int gethostname(char*, int);
int64_t readlink(const char* path, char* buffer, size_t);
char* ttyname(int fd);
int ttyname_r(int fd, char* buffer, size_t);

int brk(void *addr);
void *sbrk(intptr_t increment);
extern void _exit(int status);  // Add declaration for _exit

#define WEXITSTATUS(status) (((status)&0xff00) >> 8)
#define WTERMSIG(status) ((status)&0x7f)
#define WIFEXITED(status) (WTERMSIG(status) == 0)

#define HOST_NAME_MAX 64

#define S_IFMT 0170000
#define S_IFDIR 0040000
#define S_IFCHR 0020000
#define S_IFBLK 0060000
#define S_IFREG 0100000
#define S_IFIFO 0010000
#define S_IFLNK 0120000
#define S_IFSOCK 0140000

#define S_ISUID 04000
#define S_ISGID 02000
#define S_ISVTX 01000
#define S_IRUSR 0400
#define S_IWUSR 0200
#define S_IXUSR 0100
#define S_IRGRP 0040
#define S_IWGRP 0020
#define S_IXGRP 0010
#define S_IROTH 0004
#define S_IWOTH 0002
#define S_IXOTH 0001

#define S_ISDIR(m) (((m)&S_IFMT) == S_IFDIR)
#define S_ISCHR(m) (((m)&S_IFMT) == S_IFCHR)
#define S_ISBLK(m) (((m)&S_IFMT) == S_IFBLK)
#define S_ISREG(m) (((m)&S_IFMT) == S_IFREG)
#define S_ISFIFO(m) (((m)&S_IFMT) == S_IFIFO)
#define S_ISLNK(m) (((m)&S_IFMT) == S_IFLNK)

#define O_RDONLY 0
#define O_WRONLY 1
#define O_RDWR 2
#define O_DIRECTORY 00200000
#define O_NOFOLLOW 00400000

int open(const char *pathname, int flags, mode_t mode);
int64_t read(int fd, void *buf, size_t count);
int64_t write(int fd, const void *buf, size_t count);
int close(int fd);

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

int getopt(int argc, char* const argv[], const char* optstring);
extern char* optarg;
extern int optind, opterr, optopt;

__END_DECLS
