#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * main - print value of args (n n n...) as (n+n+n+...)
 * @argc: argument count
 * @argv: argument vector
 * unsigned_int - print only non-negative values
 * Return: 0 or 1
 */

int main(int argc, char *argv[])
{
	unsigned int x;
	unsigned int add;
	unsigned int operand;

	if (argc < 2)
	{
		printf("%d\n", 0);
		return (0);
	}

	while (argc-- && argc > 0)
	{
		for (x = 0; argv[argc][x] != '\0'; x++)
		{
			if (!(isdigit(argv[argc][x])))
			{
				printf("Error\n");
				return (1);
			}
		}
		operand = atoi(argv[argc]);
		add = add + operand;
	}
	printf("%d\n", add);
	return (add);
}
