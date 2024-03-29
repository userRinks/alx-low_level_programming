#include "main.h"

/**
 * _strlen - print length of string
 * @s: input
 * Return: l
 */

int _strlen(char *s)
{
	int l = 0;

	while (*s != '\0')
	{
		s++;
		l++;
	}
	return (l);
}

/**
* str_concat - Concatenate two strings.
* @s1: string 1
* @s2: string 2
* Return: char
*/

char *str_concat(char *s1, char *s2)
{
	unsigned int l1, l2;
	char *conc, *tmp;

	if (!s1)
	{
		s1 = "";
	}
	else
	{
		l1 = _strlen(s1);
	}

	if (!s2)
	{
		s2 = "";
	}
	else
	{
		l2 = _strlen(s2);
	}

	conc = malloc(l1 + l2 + 1);
	if (!conc)
	{
		return (0);
	}

	tmp = conc;

	while (*s1)
	{
		*tmp++ = *s1++;
	}

	while ((*tmp++ = *s2++))
		;

	return (conc);
}
