#include "lists.h"

/**
 * _strlen - Returns the lenght of a string.
 * @s: Type char pointer
 * Return: Always 0.
 */

int _strlen(const char *s)
{
	unsigned int len;

	for (len = 0; s[len] != '\0'; len++)
	{
		/* Iterating through the string */
	}
		return (len);
}

/**
 * add_node_end - Returns length of string.
 * @str: char type pointer
 * @head: type pointer of struct
 * Return: new_node.
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *n_node, *tmp_node;

	n_node = malloc(sizeof(list_t));

	if (n_node == NULL)
	{
		return (NULL);
	}

	n_node->str = strdup(str);
	n_node->len = _strlen(str);
	n_node->next = NULL;

	if (!*head)
	{
		*head = n_node;
	}
	else
	{
		tmp_node = *head;
		while (tmp_node->next)
		{
			tmp_node = tmp_node->next;
		}
		tmp_node->next = n_node;
	}
	return (n_node);
}
