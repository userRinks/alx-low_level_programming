#include "main.h"

/**
 * _memcpy - copy value in memory block
 * @dest: pointer
 * @src: pointer
 * @n: integer
 * Return: memcpy
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	return (memcpy(dest, src, n));
}
