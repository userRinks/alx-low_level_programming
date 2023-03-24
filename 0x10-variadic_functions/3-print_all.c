#include "variadic_functions.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_int - print integer
 * @bruh: arguments from print_all
 */

void print_int(va_list bruh)
{
	printf("%d", va_arg(bruh, int));
}

/**
 * print_float - print float
 * @bruh: arguments from print_all
 */

void print_float(va_list bruh)
{
	printf("%f", va_arg(bruh, double));
}

/**
 * print_char - print char
 * @bruh: arguments from print_all
 */

void print_char(va_list bruh)
{
	printf("%c", va_arg(bruh, int));
}

/**
 * print_str - print string
 * @bruh: arguments from print_all
 */

void print_str(va_list bruh)
{
	char *s = va_arg(bruh, char *);

	s == NULL ? printf("(nil)") : printf("%s", s);

}

/**
 * print_all - prints any type
 * @format: arguments to print
 */

void print_all(const char * const format, ...)
{
	va_list bruh;
	int i = 0, j = 0;
	char *sep = "";

	definition arguments[] = {
		{ "i", print_int },
		{ "f", print_float },
		{ "c", print_char },
		{ "s", print_str },
		{NULL, NULL}
	};

	va_start(bruh, format);

	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (*arguments[j].type == format[i])
			{
				printf("%s", sep);
				arguments[j].func(bruh);
				sep = ", ";
			break;
			}
			j++;
		}
		i++;
	}

	printf("\n");
	va_end(bruh);
}
