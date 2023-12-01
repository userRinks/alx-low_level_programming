#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 * Return: A pointer to the created sorted hash table, or NULL if it fails.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Adds an element to the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key string.
 * @value: The value string.
 * Return: 1 if it succeeds, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	/* Check if key already exists, update value if true */
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return (1);
		}
		current = current->next;
	}

	/* Key doesn't exist, create a new node */
	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	/* Insert new node in the linked list at the right place */
	insert_sorted_node(ht, new_node);

	return (1);
}


/**
 * shash_table_get - Retrieves a value associated with a key.
 * @ht: The sorted hash table.
 * @key: The key to look for.
 * Return: The value associated with the element, or NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || key == NULL)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);

	/* Search for the key in the linked list at the index */
	current = ht->array[index];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
			return (current->value);
		current = current->next;
	}

	return (NULL);
}


/**
 * shash_table_print - Prints the sorted hash table using the sorted linked list.
 * @ht: The sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	current = ht->shead;
	printf("{");
	while (current != NULL)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->snext != NULL)
			printf(", ");
		current = current->snext;
	}
	printf("}\n");
}


/**
 * shash_table_print_rev - Prints the hash table key/value pairs in reverse order using the sorted linked list.
 * @ht: The sorted hash table.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current;

	if (ht == NULL)
		return;

	current = ht->stail;
	printf("{");
	while (current != NULL)
	{
		printf("'%s': '%s'", current->key, current->value);
		if (current->sprev != NULL)
			printf(", ");
		current = current->sprev;
	}
	printf("}\n");
}


/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *current, *temp;

	if (ht == NULL)
		return;

	for (i = 0; i < ht->size; i++)
	{
		/* Traverse the linked list at the current index */
		current = ht->array[i];
		while (current != NULL)
		{
			/* Free allocated memory for key and value */
			free(current->key);
			free(current->value);

			/* Save the next node before freeing the current node */
			temp = current->next;
			free(current);

			/* Move to the next node in the linked list */
			current = temp;
		}
	}

	/* Free the array and the hash table structure itself */
	free(ht->array);
	free(ht);
}

/**
 * insert_sorted_node - Inserts a new node into the sorted linked list.
 * @ht: The sorted hash table.
 * @new_node: The new node to insert.
 */
void insert_sorted_node(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *current;

	if (ht->shead == NULL)
	{
		/* Empty list, insert as the head and tail */
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else if (strcmp(new_node->key, ht->shead->key) < 0)
	{
		/* Insert at the beginning of the list */
		new_node->snext = ht->shead;
		ht->shead->sprev = new_node;
		ht->shead = new_node;
	}
	else
	{
		/* Traverse the list to find the right place to insert */
		current = ht->shead;
		while (current->snext != NULL && strcmp(new_node->key, current->snext->key) > 0)
			current = current->snext;

		if (current->snext == NULL)
		{
			/* Insert at the end of the list */
			current->snext = new_node;
			new_node->sprev = current;
			ht->stail = new_node;
		}
		else
		{
			/* Insert in the middle of the list */
			new_node->snext = current->snext;
			new_node->sprev = current;
			current->snext->sprev = new_node;
			current->snext = new_node;
		}
	}

	/* Insert into the array as well */
	insert_array_node(ht, new_node);
}

/**
 * insert_array_node - Inserts a new node into the array.
 * @ht: The sorted hash table.
 * @new_node: The new node to insert.
 */
void insert_array_node(shash_table_t *ht, shash_node_t *new_node)
{
	unsigned long int index;

	index = key_index((unsigned char *)new_node->key, ht->size);
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
}
