#include "main.h"

/**
 * print_last_digit - prints the last digit of a number
 * @n:  is the int that will use for the argument of the function
 * Return: integer value
 */

int print_last_digit(int n)
{
	int i;

	i = n % 10;

	if (i < 0)
		i = i * -1;

	_putchar(i + '0');

	return (i);
}
