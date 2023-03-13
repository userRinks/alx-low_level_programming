#include <stdio.h>
#include <stdlib.h>

/**
 * main - print value of two arguments as (n n) computed as (nxn)
 * @argc: argument count
 * @argv: argument vector
 * atoi - argument to integer (converts string to int)
 * Return: 0 or 1
 */

int main(int argc, char *argv[])
{
	if (argc == 3)
	{
		printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
		return (0);
	}
	else
		printf("Error\n");
	return (1);
}
