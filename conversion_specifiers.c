#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf_conv_spec - Prints formatted output to stdout
 * @format: A string containing zero or more conversion specifiers
 *
 * Return: The number of characters printed (excluding the null byte used to
 *         end output to strings), or -1 if an error occurred.
 */
int _printf_conv_spec(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;  

            switch (*format) {
                case 'c': {
                    char c = va_arg(args, int);
                    putchar(c);
                    printed_chars++;
                    break;
                }

                case 's': {
                    char *s = va_arg(args, char *);
                    fputs(s, stdout);
                    printed_chars += strlen(s);
                    break;
                }

                case '%': {
                    putchar('%');
                    printed_chars++;
                    break;
                }

                case 'd':
                case 'i': {
                    int num = va_arg(args, int);
                    printf("%d", num);
                    printed_chars += num_chars(num);
                    break;
                }

                default: {
            
                    putchar('%');
                    putchar(*format);
                    printed_chars += 2;
                    break;
                }
            }
        } else {
            putchar(*format);
            printed_chars++;
        }

        format++;
    }

    va_end(args);

    return (printed_chars);
}

/**
 * num_chars - Calculates the number of characters required to represent an
 *             integer as a string in base 10
 * @n: The integer to be converted
 *
 * Return: The number of characters required to represent the integer as a
 *         string in base 10
 */
int num_chars(int n)
{
    int count = 0;

    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        count++;
        n = -n;
    }

    while (n > 0) {
        count++;
        n /= 10;
    }

    return (count);
}

