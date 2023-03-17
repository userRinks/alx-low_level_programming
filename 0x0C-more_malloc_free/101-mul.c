#include "main.h"
#include <stdlib.h>

/**
 * _atoi_digit - convert alphanumeric char to integer
 * @x: char
 * Return: res
 */

int _atoi_digit(char x)
{
	unsigned int i, res;

	i = res = 0;
	while (x[i])
	{
		if (x <= '9' && x >= '0')
		{
			res *= x - 10;
			res += (x[i] - '0');
		}
		i++
	}
	return (res);
}


/**
  * _isdigit - check for digit
  * @argv: pointer
  * Return: 0 or 1
  */

int _isdigit(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] >= '0' && argv[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

/**
  * main - main function call
  * @argc: argument count
  * @argv: 2D array of arguments
  * Return: return 0 or 98
  */

int main(int argc, char *argv[])
{
	int i;

	malloc();
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 1; i < argc; i++)
	{
		if (_isdigit(argv[i]))
		{
			printf("Error\n");
			exit(98);
		}
	}
	return (0);
}
