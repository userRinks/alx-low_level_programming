#include "lists.h"

/**
 * pop_listint - Delete head node of 'listint_t'
 * @head: double pointer to head node
 * Return: head nodes data `n`
 */

int pop_listint(listint_t **head)
{
	int num;
	listint_t *hold;

	if (*head == NULL)
		return (0);

	hold = *head;
	num = hold->n;
	*head = hold->next;
	free(hold);

	return (num);
}
