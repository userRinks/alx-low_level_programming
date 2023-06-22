#include "variadic_functions.h"
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_numbers - print all numbers with a separator
 * @separator: separate numbers
 * @n: number of undefined arguments
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list bruh;
	unsigned int i;

	va_start(bruh, n);

	for (i = 0; i < n; i++)
	{
		printf("%i", va_arg(bruh, int));
		if (i != n - 1 && separator != NULL)
		{
			printf("%s", separator);
		}
	}

	va_end(bruh);

	putchar('\n');
}
