#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf_conv - prints output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: number of characters printed
 */
int _printf_conv(const char *format, ...)
{
    va_list args;
    int len = 0;
    int n;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'd' || *format == 'i')
            {
                n = va_arg(args, int);
                len += printf("%d", n);
            }
            else if (*format == 'c')
            {
                n = va_arg(args, int);
                len += printf("%c", n);
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                len += printf("%s", str);
            }
            else if (*format == '%')
            {
                len += printf("%%");
            }
            else
            {
                printf("Unknown conversion specifier\n");
            }
        }
        else
        {
            putchar(*format);
            len++;
        }
        format++;
    }

    va_end(args);

    return (len);
}

