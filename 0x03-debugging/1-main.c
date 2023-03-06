#include <stdio.h>

/**
* main - no longer causes an infinite loop
* Description: bug in code edited out as comment
* Return: 0
*/

int main(void)
{
	int i;

	printf("Infinite loop incoming :(\n");

	i = 0;

/*
 * while (i < 10)
 * {
 * putchar(i);
 * }
*/

	printf("Infinite loop avoided! \\o/\n");

	return (0);
}
