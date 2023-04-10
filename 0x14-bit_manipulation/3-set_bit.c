#include <stdio.h>
#include "main.h"

/**
 * set_bit - sets the value of a bit to 1 at a given index
 * @n: unsigned long integer bit
 * @index: index of bit
 * Return:
 *	(1) if success
 *	(-1) if fail
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1); /* index out of range */
	}

	*n |= 1UL << index;
	return (1); /* success */
}
