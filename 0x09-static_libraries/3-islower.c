#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * _islower - check if character is in lowercase
 * @c: integer
 * Return: 0
 */

int _islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
