#include "main.h"

/**
 * rev_string - prints reversed string, followed by a new line
 * @s: pointer to print string
 * return: void
*/

void rev_string(char *s)
{
	int length, a, b;
	char c1, c2;

	for (length = 0; s[length] != '\0'; length++)
	{
	}

	a = length - 1;
	b = 0;

	while (a > b)
	{
		c1 = s[b];
		c2 = s[a];
		s[b] = c2;
		s[a] = c1;
		a--;
		b++;
	}
}
