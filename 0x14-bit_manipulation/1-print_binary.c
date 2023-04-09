#include <stdio.h>
#include "main.h"
#include <limits.h>

/**
 * print_binary - compute and print numbers in binary without stack overflow
 * @n: integer
 */

void print_binary(unsigned long int n)
{
	int bits = sizeof(unsigned long int) * CHAR_BIT;

	int most_significant_bits = 0;

	for (int i = bits - 1; i >= 0; i--)
	{
		if ((n >> i) & 1)
		{
			most_significant_bits = i;
			break;
		}
	}
	for (int i = most_significant_bits; i >= 0; i--)
	{
		putchar((n & (1UL << i)) ? '1' : '0');
	}
}
