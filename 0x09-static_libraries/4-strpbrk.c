#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * _strpbrk - search string for any of the specified characters
 * @s: pointer to string
 * @accept: pointer
 * Return: strpbrk
 */

char *_strpbrk(char *s, char *accept)
{
	return (strpbrk(s, accept));
}
