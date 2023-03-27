#include "main.h"

/**
 * print_char - prints a char
 * @args: list of arguments
 * @count: pointer to the count of printed characters
 * Return: void
 */

void print_char(va_list args, int *count)
{
	int c = va_arg(args, int);

	putchar(c);
	(*count)++;
}

/**
 * print_string - prints a string
 * @args: list of arguments
 * @count: pointer to the count of printed characters
 *
 * Return: void
 */
void print_string(va_list args, int *count)
{
	char *s = va_arg(args, char *);

	while (*s)
	{
		putchar(*s++);
		(count)++;
	}
}

/**
 * print_integer - prints an integer
 * @args: list of arguments
 * @count: pointer to the count of printed characters
 * Return: void
 */
void print_integer(va_list args, int *count)
{
	int n = va_arg(args, int);

	if (n < 0)
	{
		putchar('-');
		n = -n;
		(*count)++;
	}
	if (n / 10)
	{
		print_integer(args, count);
	}
	putchar(n % 10 + '0');
	(*count)++;
}

/**
 * _printf - produces output according to a format
 * @format: character string
 * @...: optional arguments
 * Return: number of characters printed or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	for (; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				print_char(args, &count);
			else if (format[i] == 's')
				print_string(args, &count);
			else if (format[i] == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				putchar('%');
				putchar(format[i]);
				count += 2;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
