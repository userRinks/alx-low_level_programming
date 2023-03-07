#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: buffer array
 * @t: constant byte
 * @n: number of bytes of memory area to fill
 * Return: Pointer to memory address `s`
 */

char *_memset(char *s, char t, unsigned int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		s[i] = t;
		i++;
		n--;
	}

	return (s);
}
