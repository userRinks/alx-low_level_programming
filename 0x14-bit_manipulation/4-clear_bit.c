#include <stdio.h>
#include "main.h"

/**
 * clear_bit - set value of a bit to (0) at given index
 * @n: pointer to bit
 * @index: index of bit
 * Return:
 *	(-1) if success
 *	(0) if fail
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);  /* index out of range */
	}

	*n &= ~(1UL << index);

	return (1);
}
