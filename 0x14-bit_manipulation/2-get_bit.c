#include <stdio.h>
#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: bit
 * @index: index of bits
 * Return:
 *	(-1) if index is out of range
 *	(0) if no errors
 */

int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);  /* if index out of range */
	}

	if ((n & mask) != 0)
	{
		return (1);
	}

	else
	{
		return (0);
	}
}
