#include "main.h"

/**
 * _memset - return value of pointer to memory block
 * @s: string
 * @b: integer
 * @n: integer
 * Return: memset
 */

char *_memset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
