#include "main.h"

/**
 * is_prime_number - check if function returns prime number
 * @n: integer value
 * Return: 1 or 0
 */

int is_prime_number(int n)
{
	return (am_i_prime(n, 2));
}

/**
 * am_i_prime - check if numbers less than are its factors
 * @n: integer
 * @p: integer
 * Return: integer value
 */

int am_i_prime(int n, int p)
{
	if (p >= n && n > 1)
		return (1);
	else if (n % p == 0 || n <= 1)
		return (0);
	else
		return (am_i_prime(n, p + 1));
}
