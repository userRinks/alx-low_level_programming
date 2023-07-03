#include "lists.h"

/**
 * free_listint - free `listint_t`
 * @head: head of linked list
 */

void free_listint(listint_t *head)
{
	listint_t *hold;

	while (head != NULL)
	{
		hold = head;
		head = head->next;
		free(hold);
	}
}
