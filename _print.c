#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string
 * @...: optional arguments
 * Return: number of characters printed or -1 on error
 */
int _printf(const char *format, ...)
{
	int i = 0, printed = 0, printed_char = 0;
	int flags, width, precision, size, count = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if  (!format)
		return (-1);

	va_start(args, format);

	while (format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[count++] = format[i];
			if (count == BUFFER_SIZE)
				print_buffer(buffer, &count);
			printed_char++;
		}
		else
		{
			print_buffer(buffer, &count);
			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = ger_ precision(format, &i, args);
			size = get_size(format, &i);
			++i;
			printed = handle_print(format, &i, args, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_char += printed;
		}
		i++;
	}
	print_buffer(buffer, &count);
	va_end(args);
	return (printed_char);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*count > 0)
		write(1, &buffer[0], *count);
	*count = 0;
}

