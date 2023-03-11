#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * _strspn - print index of first character found
 * @s: pointer to string
 * @accept: pointer
 * Return: strspn
 */

unsigned int _strspn(char *s, char *accept)
{
	return (strspn(s, accept));
}
