#include "main.h"
#include <ctype.h>
#include <string.h>

/**
 * is_valid_number - checks if a string contains only digits
 * @num: string to check
 * Return: 1 if valid number
 *	   0 if otherwise
 */
int is_valid_number(char *num)
{
	int i;

	for (i = 0; num[i]; i++)
	{
		if (!isdigit(num[i]))
			return (1);
	}

	return (0);
}

/**
 * multiply - performs the multiplication of two numbers
 * @num1: first number
 * @num2: second number
 * Return: pointer to the result string
 */
char *multiply(char *num1, char *num2)
{
	int len1, len2, lenout, i, j, k, carry;
	char *result;

	len1 = strlen(num1);
	len2 = strlen(num2);
	lenout = len1 + len2;
	result = malloc(sizeof(char) * (lenout + 1));

	if (result == NULL)
	{
		printf("Error\n");
		exit(98);
	}

	for (i = 0; i < lenout; i++)
		result[i] = '0';
	result[lenout] = '\0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;

		for (j = len2 - 1, k = lenout - (len1 - i); j >= 0; j--, k--)
		{
			int digit = (num1[i] - '0') * (num2[j] - '0') + (result[k] - '0') + carry;

			result[k] = (digit % 10) + '0';
			carry = digit / 10;
		}

		if (carry > 0)
			result[k] = (carry % 10) + '0';
	}

	return (result);
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success
 *	   1 if otherwise
 */
int main(int argc, char *argv[])
{
	char *num1, *num2, *result;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	if (!is_valid_number(num1) || !is_valid_number(num2))
	{
		printf("Error\n");
		return (98);
	}

	if (strcmp(num1, "0") == 0 || strcmp(num2, "0") == 0)
	{
		printf("0\n");
		return (0);
	}

	result = multiply(num1, num2);
	printf("%s\n", result);
	free(result);

	return (0);
}
