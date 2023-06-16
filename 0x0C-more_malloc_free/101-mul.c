#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * is_digit - Checks if a character is a digit.
 * @c: The character to check.
 * Return: 1 if the character is a digit, 0 otherwise.
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * Times - Performs the actual multiplication.
 * @num1: The first number as a string.
 * @num2: The second number as a string.
 * @len1: The length of the first number.
 * @len2: The length of the second number.
 * Return: The resulting array of the multiplication.
 */
int *Times(char *num1, char *num2, int len1, int len2)
{
	int len_r = len1 + len2;
	int *result = (int *)calloc(len_r, sizeof(int));
	int i, j, carry, product;

	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0') + carry + result[i + j + 1];
			result[i + j + 1] = product % 10;
			carry = product / 10;
		}
		result[i] += carry;
	}

	return (result);
}

/**
 * printResult - Prints the result.
 * @result: The array containing the result.
 * @len_r: The length of the result array.
 */
void printResult(int *result, int len_r)
{
	int i = 0;

	while (i < len_r && result[i] == 0)
		i++;

	if (i == len_r)
	{
		putchar('0');
		putchar('\n');
	}
	else
	{
		while (i < len_r)
		{
			putchar(result[i] + '0');
			i++;
		}
		putchar('\n');
	}
}

/**
 * multiply - Multiplies two positive numbers.
 * @num1: The first number as a string.
 * @num2: The second number as a string.
 */
void multiply(char *num1, char *num2)
{
	int len1 = 0, len2 = 0;
	int *result;

	while (num1[len1] && is_digit(num1[len1]))
		len1++;

	while (num2[len2] && is_digit(num2[len2]))
		len2++;

	result = Times(num1, num2, len1, len2);

	printResult(result, len1 + len2);

	free(result);
}

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 * Return: 0 on success, 98 on failure.
 */
int main(int argc, char **argv)
{
	char *num1, *num2;
	int i;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	for (i = 0; num1[i]; i++)
	{
		if (!is_digit(num1[i]))
		{
			printf("Error\n");
			return (98);
			}
	}

	for (i = 0; num2[i]; i++)
	{
		if (!is_digit(num2[i]))
		{
			printf("Error\n");
			return (98);
		}
	}

	multiply(num1, num2);

	return (0);
}
