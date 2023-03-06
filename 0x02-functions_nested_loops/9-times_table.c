#include "main.h"

/**
 * times_table - prints times table
 * Return:void
 */

void times_table(void)
{

int a = 0;
int b;
int value;
while (a <= 9)
{
	b = 0;
	while (b <= 9)
	{
		value = a * b;
		if (b == 0)
		{
			_putchar('0' + value);
		}
		else if (value < 10)
		{
			_putchar(' ');
			_putchar('0' + value);
		}
		else
		{
			_putchar('0' + value / 10);
			_putchar('0' + value % 10);
		}

		if (b < 9)
		{
			_putchar(',');
			_putchar(' ');
		}
		b++;
	}
	_putchar('\n');
	a++;
	}
}
