#include "main.h"
#include <stdio.h>

/**
 * is_prime_number - check if function returns prime number
 * @n: integer value
 * Return: 1 or 0
 */

int is_prime_number(int n)
{
	return (check_prime(n, 2));
}

/**
 * check_prime - check if all numbers < n can divide it
 * @n: int
 * @p: int
 * Return: int
 */

int check_prime(int n, int p)
{

	if (p >= n && n > 1)
		return (1);
	else if (n % p == 0 || n <= 1)
		return (0);
	else
		return (check_prime(n, p + 1));
}
