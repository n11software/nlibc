#pragma once

#include <sys/syscall.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline long syscall(long num, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6) {
    long ret;
    __asm__ volatile(
        "movq %1, %%rax\n"
        "movq %2, %%rdi\n"
        "movq %3, %%rsi\n"
        "movq %4, %%rdx\n"
        "movq %5, %%r10\n"
        "movq %6, %%r8\n"
        "movq %7, %%r9\n"
        "syscall\n"
        : "=a"(ret)
        : "r"(num), "r"(arg1), "r"(arg2), "r"(arg3), "r"(arg4), "r"(arg5), "r"(arg6)
        : "rcx", "r11", "memory"
    );
    return ret;
}

#ifdef __cplusplus
}
#endif 