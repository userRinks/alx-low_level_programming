#include "lists.h"

/**
 * delete_nodeint_at_index - delete node at index of 'listint_t'
 * @head: double header to head
 * @index: index of node to delete, starting at 0
 * Return:
 *	(If successful) 0
 *	(If unsuccessful) 1
 */

 int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current;
	listint_t *hold;
	unsigned int i;

	i = 0;
	current = *head;
	if (*head == NULL)
		return (-1);

	while (i < index)
	{
		i++;
		hold = current;
		if (current->next)
			current = current->next;
		else
			return (-1);
	}

	if (index == 0)
		*head = current->next;
	else if (current->next)
		hold->next = current->next;
	else
		hold->next = NULL;

	free(current);
	return (1);
}
