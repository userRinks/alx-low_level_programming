#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * _strchr - find character in string
 * @s: pointer to string
 * @c: character
 * Return: strchr
 */

char *_strchr(char *s, char c)
{
	return (strchr(s, c));
}
