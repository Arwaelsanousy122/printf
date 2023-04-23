#include <stdarg.h>
#include "main.h"
#include <stdout.h>
#include <stdio.h>

/**
 * _printf - building ower own printf function.
 *@format: parameter for input format
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings).
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	for (*format != '\0')
	{
		if (*format == '%')
		{
		format++;
		switch (*format)
		{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 's':
				printf("%s", va_arg(args, char*));
				break;
		}
		else
		{
			printf("%c", *format);
		}
		format++;
		}
	}
	va_end(args);
}

/**
 * main - entry point
 *
 * Return: 0
 */

int main(void)
{
	char c = 'A';
	char str[] = "Hello world!";

	_printf("character: %c\n, String: %s\n", c, str);
	return (0);
}
