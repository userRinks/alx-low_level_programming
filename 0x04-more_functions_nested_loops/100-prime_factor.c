#include <stdio.h>
#include <math.h>

/**
 * main - main; checking numbers
 * Return: 0
 */

int main(void)
{
	int i;
	long number = 612852475143;

	for (i = (int) sqrt(number); i > 2; number++)
	{
		if (number % i == 0)
		{
			printf("%ld\n", i);
			break;
		}
	}
	return (0);
}
