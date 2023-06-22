#include "variadic_functions.h"

/**
 * sum_them_all - add all parameters
 * @n: number of extra parameters
 * Return: sum
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	va_list bruh;
	int sum;

	i = 0;

	if (n == 0)
	{
		return (0);
	}

	sum = 0;
	va_start(bruh, n);
	while (i < n)
	{
		sum = sum + va_arg(bruh, int);
		i++;
	}

	va_end(bruh);
	return (sum);

}
