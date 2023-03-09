#include "main.h"

/**
 * _sqrt_recursion - return square root
 * @n: int number
 * Return: -1 or square root
 */

int _sqrt_recursion(int n)
{
	return (root(n, 1));
}

/**
 * solve - function to solve square root
 * @n: int value
 * @root: square root
 * Return: int
 */

int solve(int n, int root)
{
	if (root * root == n)
		return (root);
	else if (root * root < n)
		return (solve(n, root + 1));
	else
		return (-1);
}
