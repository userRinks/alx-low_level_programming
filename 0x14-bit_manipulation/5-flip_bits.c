#include <stdio.h>
#include "main.h"

/**
 * flip_bits - return number of bits needed to flip to get from n to m
 * @n: first number
 * @m: second number
 * Return: number of bits needed to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int ya_need = 0;
	unsigned long int calc = n ^ m;

	while (calc)
	{
		ya_need += calc & 1;
		calc >>= 1;
	}

	return (ya_need);
}
