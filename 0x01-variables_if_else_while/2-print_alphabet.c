#include <stdio.h>
#include <stdlib.h>

/**
 * main - main block
 * Description: Get a random number, check its last digit then compare it with 5
 * Return: 0
 */
int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		putchar(c);
		c++;
	}

	putchar('\n');
	return (0);
}
