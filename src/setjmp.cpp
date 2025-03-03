#include <setjmp.h>

int setjmp(jmp_buf env) {
    asm volatile(
        "movq %%rbx, %0\n"
        "movq %%rbp, %1\n"
        "movq %%r12, %2\n"
        "movq %%r13, %3\n"
        "movq %%r14, %4\n"
        "movq %%r15, %5\n"
        "movq %%rsp, %%rax\n"
        "addq $8, %%rax\n"
        "movq %%rax, %6\n"
        "movq (%%rsp), %%rax\n"
        "movq %%rax, %7\n"
        : "=m"(env[0].rbx),
          "=m"(env[0].rbp),
          "=m"(env[0].r12),
          "=m"(env[0].r13),
          "=m"(env[0].r14),
          "=m"(env[0].r15),
          "=m"(env[0].rsp),
          "=m"(env[0].rip)
        :
        : "rax", "memory"
    );
    return 0;
}

void longjmp(jmp_buf env, int val) {
    if (val == 0)
        val = 1;
    
    asm volatile(
        "movq %0, %%rbx\n"
        "movq %1, %%rbp\n"
        "movq %2, %%r12\n"
        "movq %3, %%r13\n"
        "movq %4, %%r14\n"
        "movq %5, %%r15\n"
        "movq %6, %%rsp\n"
        "movl %8, %%eax\n"
        "jmpq *%7\n"
        :
        : "m"(env[0].rbx),
          "m"(env[0].rbp),
          "m"(env[0].r12),
          "m"(env[0].r13),
          "m"(env[0].r14),
          "m"(env[0].r15),
          "m"(env[0].rsp),
          "m"(env[0].rip),
          "r"(val)
        :
    );
    __builtin_unreachable();
}