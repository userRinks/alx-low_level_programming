#include <stdlib.h>

/**
 * _strdup - copy memory block
 * @str: pointer
 * Return: pointer
 */

char *_strdup(char *str)
{
	char *s;
	int i = 0, j;

	if (!str)
	{
		return (NULL);
	}

	while (*(str + i))
	{
		i++;
	}

	s = malloc(sizeof(char) * (i + 1));

	if (s == NULL)
	{
		return (NULL);
	}

	for (j = 0; j < i; j++)
	{
		s[j] = str[j];
	}
	return (s);
}
