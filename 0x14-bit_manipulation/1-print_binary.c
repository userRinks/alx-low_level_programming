#include <stdio.h>
#include "main.h"
#include <limits.h>

/**
 * print_binary_helper - prevent stack overflow, print most significant bits
 * @n: integer
 * @msb: most significant bits
 */

void print_binary_helper(unsigned long int n, int msb)
{
	if (n == 0 || msb == -1)
	{
		return;
	}
	print_binary_helper(n >> 1, msb - 1);
	putchar((n & 1) ? '1' : '0');
}


/**
 * print_binary - prevent stack overflow, print most significant bits
 * @n: integer
 */

void print_binary(unsigned long int n)
{
	int msb = -1;
	unsigned long int tmp = n;

	while (tmp > 0)
	{
		tmp >>= 1;
		msb++;
	}
	if (msb == -1)
	{
		putchar('0');
	}
	else
	{
		print_binary_helper(n, msb);
	}
}
