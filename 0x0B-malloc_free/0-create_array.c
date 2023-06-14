#include "main.h"

/**
 * create_array - Creates and initializes an array with a specific character
 * @size: The size of the array
 * @c: The character to initialize the array with
 * Return: The pointer to the created array, or (NULL)
 */

char *create_array(unsigned int size, char c)
{
	char *buffer;
	unsigned int position;

	if (size == 0)
	{
		return (NULL);
	}

	/* Define values with malloc */
	buffer = (char *) malloc(size * sizeof(c));

	if (buffer == 0)
	{
		return (NULL);
	}

	else
	{
		position = 0;
		while (position < size)  /* While for array */
		{
			*(buffer + position) = c;
			position++;
		}
		return (buffer);
	}
}
