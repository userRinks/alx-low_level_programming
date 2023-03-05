#include <stdio.h>

/**
 * main - main; checking numbers
 * Return: 0
 */

int main(void)
{
	int i;
	long number = 612852475143;

	for (number = 2; number < i; number++)
	{
		if (i % number == 0)
		{
			i = i / number;
		}
	}
	printf("%ld\n", number);
	return (0);
}
