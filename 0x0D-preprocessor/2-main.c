#include <stdio.h>

/**
 * main - print name of file it was compiled from + new line
 * Return: always (0)
 */

int main(void)
{
	printf("%s\n", __FILE__);
	return (0);
}
