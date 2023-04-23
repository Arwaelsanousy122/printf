#include "main.h"

/**
 * _printf - building ower own printf function.
 *@format: parameter for input format
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings).
 */

int _printf(const char *format, ...)
{
	int i;
	va_list args;

	va_start(args, format);
	for (i = 0; *format != '\0'; i++)
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
			case '%':
				printf("%%", va_arg(args, char*));
				break;
		}
		}
		else
		{
			printf("%c", *format);
		}
		format++;
	}
	va_end(args);
	return (0);
}
