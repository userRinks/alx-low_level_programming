#include "lists.h"

/**
 * free_list - free list_t
 * @head: pointer type struct for list_t
 * Return: free head
 */

void free_list(list_t *head)
{
	list_t *tmp;

	tmp = head;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
	free(head);
}
