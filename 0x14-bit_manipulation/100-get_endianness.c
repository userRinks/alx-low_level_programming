#include <stdio.h>
#include "main.h"

/**
 * get_endianness - check if your system is Big or Little endian
 * Return:
 *	(1) if Big Endian
 *	(0) if Little Endian
 */

int get_endianness(void)
{
	unsigned int x = 1;
	char *c = (char *)&x;

	return ((int) *c);
}
