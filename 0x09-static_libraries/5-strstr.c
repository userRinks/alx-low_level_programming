#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/**
 * _strstr - locate substring
 * @haystack: pointer to string
 * @needle: pointer to string
 * Return: strstr
 */

char *_strstr(char *haystack, char *needle)
{
	return (strstr(haystack, needle));
}
