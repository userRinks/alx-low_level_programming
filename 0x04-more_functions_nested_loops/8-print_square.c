#include "main.h"

/**
 * print_square - check for digit, print square
 * @s: size of square
 * return: void
 */

void print_square(int s)
{
	int a, b;

	b = 0;

	if (s < 1)
		_putchar('\n');

	while (b < s)
	{
		a = 0;
		while (a < s)
		{
			_putchar('#');
			a++;
		}
		_putchar('\n');
		b++;
	}
}
