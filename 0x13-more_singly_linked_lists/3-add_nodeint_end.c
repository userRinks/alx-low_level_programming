#include "lists.h"

/**
 * add_nodeint_end - add new node at the end of 'listint_t'
 * @head: double pointer to head node
 * @n: int
 * Return:
 *	(If successful) Address of new element
 *	(If unsuccessful) NULL
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *current;
	listint_t *new;

	current = *head;
	while (current && current->next != NULL)
		current = current->next;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = NULL;

	if (current)
		current->next = new;
	else
		*head = new;
	return (new);
}
