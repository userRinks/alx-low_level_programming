#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table.
 * @ht: The hash table to delete.
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current, *temp;

	/* Check for NULL hash table */
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
