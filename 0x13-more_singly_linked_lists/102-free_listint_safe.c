#include "lists.h"
#include <stdio.h>

/**
 * free_listint_safe - frees a linked list "safely"
 * @h: pointer to the first node in 'listint_t'
 * Return: number of elements in the freed list
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *current, *hold;
	size_t count;

	count = 0;
	current = *h;
	while (current != NULL)
	{
		count++;
		hold = current;
		current = current->next;
		free(hold);

		if (hold < current)
			break;
	}
	*h = NULL;

	return (count);
}
