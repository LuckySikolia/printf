#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int _printf(const char *format, ...);
void print_string(va_list args, int *count);
void print_char(va_list args, int *count);
int num_chars(int n);
int _printf_conv_spec(const char *format, ...);
int _printf_conv(const char *format, ...);

#endif
