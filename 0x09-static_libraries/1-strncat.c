#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * _strncat - concatenate strings
 * @dest: pointer
 * @src: pointer
 * @n: integer
 * Return: strncat
 */

char *_strncat(char *dest, char *src, int n)
{
	return (strncat(dest, src, n));
}
