#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

static void
printStr(const char* str)
{
	while (*str) {
		write(1, str++, 1);
	}
}

static void
printInt(int num) {
	char buf[20];
	int i = 0;
	if (num == 0) {
		write(1, "0", 1);
		return;
	}

	if (num < 0) {
		write(1, "-", 1);
		num = -num;
	}
	while (num) {
		buf[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i--) {
		write(1, &buf[i], 1);
	}
}

int
printf(const char* fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	while (*fmt) {
		if (*fmt == '%') {
			fmt++;
			switch (*fmt) {
				case 's': printStr(va_arg(args, const char *)); break;
				case 'd': printInt(va_arg(args, int)); break;
				case '%': write(1, "%", 1); break;
				default: write(1, fmt, 1); break;
			}
		} else {
			write(1, fmt, 1);
		}
		fmt++;
	}

	va_end(args);
	return 0; // fixme: doesn't return char cnt like standard printf
}
