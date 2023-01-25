#ifndef __DSL_SYSCALL_H__
#define __DSL_SYSCALL_H__

#if defined(__x86_64__) || defined(_M_X64) /* x86_64 */
#       define __SYSCALL_WRITE(ret, fd, buf, count)     __asm__ ("syscall" : "=a"(ret) : "a"(0x01), "D"(fd), "S"(buf), "d"(count))
#       define __SYSCALL_READ(ret, fd, buf, count)      __asm__ ("syscall" : "=a"(ret) : "a"(0x00), "D"(fd), "S"(buf), "d"(count))
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86) /* i386 (x86) */
#       define __SYSCALL_WRITE(ret, fd, buf, count)     __asm__ ("int $0x0080" : "=a"(ret) : "a"(0x04), "b"(fd), "c"(buf), "d"(count))
#       define __SYSCALL_READ(ret, fd, buf, count)      __asm__ ("int $0x0080" : "=a"(ret) : "a"(0x03), "b"(fd), "c"(buf), "d"(count))
#elif defined(__aarch64__) || defined(_M_ARM64) /* arm64 */
#       define __SYSCALL_WRITE(ret, fd, buf, count)     \
        __asm__ ("mov %x8, #0x0040")                     \
        __asm__ ("mov %x0, %[fd]" : : [fd] "r"())
#else
#error Unsupported arch!
#endif

#endif /* __DSL_SYSCALL_H__ */
