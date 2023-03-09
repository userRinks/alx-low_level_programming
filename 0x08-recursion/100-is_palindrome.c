#include "main.h"

/**
 * last_index - return last index of string
 * @s: pointer
 * Return: integer
 */

int last_index(char *s)
{
	int i = 0;

	if (*s > '\0')
		i += last_index(s + 1) + 1;
	return (i);
}

/**
 * is_palindrome - check for palindrome
 * am_i_pal: variable
 * @s: string
 * @*s: pointer
 * Return: 0 or 1
 */

int is_palindrome(char *s)
{
	int am_i_pal;
	int fin = last_index(s);

	return ((s, 0, fin - 1, fin % 2));
}

/**
 * am_i_pal - check if number is palindrome
 * @s: string
 * @init: starts from initial letter to final letter
 * @fin: starts from final letter to initial letter
 * @p: variable integer
 * Return: 0 or 1
 */

int am_i_pal(char *s, int init, int fin, int p)
{
	if ((init == fin && p != 0) || (init == fin + 1 && p == 0))
		return (1);
	else if (s[init] != s[fin])
		return (0);
	else
		return (am_i_pal(s, init + 1, fin - 1, p));
}
