#include "lists.h"

/**
 * add_nodeint - add new node at the beginning of 'listint_t'
 * @head: double pointer to head node
 * @n: int
 * Return:
 *	(If successful) Address of new element
 *	(If unsuccessful) NULL
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *hold;
	listint_t *new;

	hold = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	*head = new;

	if (hold == NULL)
		new->next = NULL;
	else
		new->next = hold;

	return (new);
}
