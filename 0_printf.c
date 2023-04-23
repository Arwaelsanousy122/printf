#include "main.h"

/**
 * _printf - building ower own printf function.
 *@format: parameter for input format
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'd' || *format == 'i')
			{
				printf("%i", va_arg(args, int));
				count++;
			}
			if (*format == 'c')
			{
				printf("%c", va_arg(args, int));
				count++;
			}
			if (*format == 's')
			{
				printf("%s", va_arg(args, char*));
				count++;
			}
			if (*format == '%')
			{
				printf("%%", va_arg(args, int));
				count++;
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
