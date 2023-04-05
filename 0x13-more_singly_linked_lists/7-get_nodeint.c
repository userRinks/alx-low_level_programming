#include "lists.h"

/**
 * get_nodeint_at_index - find 'n'th node of a 'listint_t'
 * @head: pointer to head node
 * @index: index to find in linked list, starting at 0
 * Return:
 *	(If successful) Pointer to node
 *	(If unsuccessful) NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *current;
	unsigned int count;

	current = head;
	count = 0;
	while (count < index)
	{
		if (current)
			current = current->next;
		else
			return (NULL);
		count++;
	}

	if (current)
		return (current);
	else
		return (NULL);
}
