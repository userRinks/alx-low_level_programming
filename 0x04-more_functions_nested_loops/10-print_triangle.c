#include "main.h"

/**
 * print_triangle - check for digit, print triangle
 * @size: size of triangle
 * return: void
 */

void print_triangle(int size)
{
	int i, a, b;

	i = 0;
	a = size - 1;
	while (i < size)
	{
		a = size - 1 - i;
		b = i + 1;
		while (a > 0)
		{
			_putchar(' ');
			a--;
		}
		while (b > 0)
		{
			_putchar('#');
			b--;
		}
		_putchar('\n');
		i++;
	}

	if (size <= 0)
		_putchar('\n');
}
