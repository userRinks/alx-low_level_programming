#ifndef VARIADIC_H
#define VARIADIC_H
#include <stdarg.h>
#include <stdio.h>

int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);
int _putchar(char c);

void print_int(va_list bruh);
void print_float(va_list bruh);
void print_char(va_list bruh);
void print_str(va_list bruh);

/**
 * struct definition - struct definition of a print-type structure
 * @type: type
 * @func: function to print
 */

typedef struct definition
{
	char *type;
	void (*func)();
} definition;

#endif
