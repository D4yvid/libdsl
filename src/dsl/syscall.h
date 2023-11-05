#ifndef __DSL_SYSCALL_H__
#define __DSL_SYSCALL_H__

#if defined(__x86_64__) || defined(_M_X64) /* x86_64 */
#       define __SYSCALL_WRITE(ret, fd, buf, count)     __asm__ ("syscall" : "=a"(ret) : "a"(0x01), "D"(fd), "S"(buf), "d"(count))
#       define __SYSCALL_READ(ret, fd, buf, count)      __asm__ ("syscall" : "=a"(ret) : "a"(0x00), "D"(fd), "S"(buf), "d"(count))
#       define __SYSCALL_BRK(ret, ptr)		  __asm__ ("syscall" : "=a"(ret) : "a"(0x0c), "D"(ptr))
#elif defined(i386) || defined(__i386__) || defined(__i386) || defined(_M_IX86) /* i386 (x86) */
#       define __SYSCALL_WRITE(ret, fd, buf, count)     __asm__ ("int $0x0080" : "=a"(ret) : "a"(0x04), "b"(fd), "c"(buf), "d"(count))
#       define __SYSCALL_READ(ret, fd, buf, count)      __asm__ ("int $0x0080" : "=a"(ret) : "a"(0x03), "b"(fd), "c"(buf), "d"(count))
#       define __SYSCALL_BRK(ret, ptr)		  __asm__ ("int $0x0080" : "=a"(ret) : "a"(0x2d), "b"(ptr))
#elif defined(__aarch64__) || defined(_M_ARM64) /* arm64 */
#       define __SYSCALL_WRITE(ret, fd, buf, count)		     \
		__asm__ ("mov w0, %w0" : : "r"(fd));		    \
		__asm__ ("mov x1, %x0" : : "r"(buf));		   \
		__asm__ ("mov w2, %w0" : : "r"(count));		 \
		__asm__ ("mov x8, #0x40");			      \
		__asm__ ("svc #0x0000");				\
		__asm__ ("mov %w0, w0" : "=r"(ret))
#       define __SYSCALL_READ(ret, fd, buf, count)		      \
		__asm__ ("mov w0, %w0" : : "r"(fd));		    \
		__asm__ ("mov x1, %x0" : : "r"(buf));		   \
		__asm__ ("mov w2, %w0" : : "r"(count));		 \
		__asm__ ("mov x8, #0x3f");			      \
		__asm__ ("svc #0x0000");				\
		__asm__ ("mov %w0, w0" : "=r"(ret));
#       define __SYSCALL_BRK(ret, ptr)				  \
		__asm__ ("mov x0, %x0" : : "r"(ptr));		   \
		__asm__ ("mov x8, #0xd6");			      \
		__asm__ ("svc #0x0000");				\
		__asm__ ("mov %w0, w0" : "=r"(ret));
#else
#error Unsupported architecture!
#endif

#endif /* __DSL_SYSCALL_H__ */
