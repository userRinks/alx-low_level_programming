#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * _memset - return value of pointer to memory block
 * @s: string
 * @b: integer
 * @n: integer
 * Return: memset
 */

char *_memset(char *s, char b, unsigned int n)
{
	return (memset(s, b, n));
}
