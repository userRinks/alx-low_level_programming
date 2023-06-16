#include "main.h"

#include "bootcamp.h"
#include <limits.h>

/**
 * str_len - Finds the length of a string.
 * @str: Input pointer to string.
 * Return: Length of the string.
 */
int str_len(char *str)
{
	int length;

	for (length = 0; *str != '\0'; length++)
		length++, str++;
	return (length / 2);
}

/**
 * _calloc - Allocates memory for an array using malloc.
 * @bytes: Bytes of memory needed per size requested.
 * @size: Size in bytes of each element.
 * Return: Pointer to the allocated memory.
 */
void *_calloc(unsigned int bytes, unsigned int size)
{
	unsigned int i;
	char *ptr;

	if (bytes == 0 || size == 0)
		return (NULL);
	if (size >= UINT_MAX / bytes || bytes >= UINT_MAX / size)
		return (NULL);
	ptr = malloc(size * bytes);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < bytes * size; i++)
		ptr[i] = 0;
	return ((void *)ptr);
}

/**
 * add_arrays - Adds two arrays of integers.
 * @mul_result: Pointer to array with numbers from the product.
 * @sum_result: Pointer to array with numbers from the total sum.
 * @length: Length of both arrays.
 * Return: void
 */
void add_arrays(int *mul_result, int *sum_result, int length)
{
	int i = 0, length2 = length - 1, carry = 0, sum;

	while (i < length)
	{
		sum = carry + mul_result[length2] + sum_result[length2];
		sum_result[length2] = sum % 10;
		carry = sum / 10;
		i++;
		length2--;
	}
}

/**
 * is_digit - Checks if a character is a digit.
 * @c: Input character to check.
 * Return: 0 on failure, 1 on success.
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	printf("Error\n");
	return (0);
}

/**
 * multiply - Multiplies two numbers and prints the result.
 * @factor1: Factor number 1 (the smaller of the two numbers).
 * @len1: Length of factor 1.
 * @factor2: Factor number 2 (the larger of the two numbers).
 * @len2: Length of factor 2.
 * @length: Length of the result arrays.
 * Return: Pointer to the result array.
 */
int *multiply(char *factor1, int len1, char *factor2, int len2, int length)
{
	int i = 0, index1 = len1 - 1;
	int index2, product, carry, digit, *mul_result, *sum_result;

	sum_result = _calloc(sizeof(int), length);
	while (i < len1)
	{
		mul_result = _calloc(sizeof(int), length);
		index2 = len2 - 1, digit = (length - 1 - i);
		if (!is_digit(factor1[index1]))
			return (NULL);
		carry = 0;
		while (index2 >= 0)
		{
			if (!is_digit(factor2[index2]))
				return (NULL);
			product = (factor1[index1] - '0') * (factor2[index2] - '0');
			product += carry;
			mul_result[digit] += product % 10;
			carry = product / 10;
			digit--, index2--;
		}
		add_arrays(mul_result, sum_result, length);
		free(mul_result);
	    i++, index1--;
	}
	return (sum_result);
}

/**
 * print_result - Prints the resulting array.
 * @result: Pointer to the array with numbers to print.
 * @length: Length of the result array.
 * Return: void
 */
void print_result(int *result, int length)
{
	int i = 0;

	while (result[i] == 0 && i < length)
		i++;
	if (i == length)
		_putchar('0');
	while (i < length)
		_putchar(result[i++] + '0');
	_putchar('\n');
}

/**
 * main - Multiplies two input numbers of large lengths and prints the result.
 * @argc: Input count of arguments.
 * @argv: Input array of string arguments.
 * Return: 0 on success.
 */
int main(int argc, char **argv)
{
	int len1, len2, length, temp, *result;
	char *factor1, *factor2;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	len1 = str_len(argv[1]), len2 = str_len(argv[2]);
	length = len1 + len2;
	if (len1 < len2)
		factor1 = argv[1], factor2 = argv[2];
	else
	{
		factor1 = argv[2], factor2 = argv[1];
		temp = len2, len2 = len1, len1 = temp;
	}
	result = multiply(factor1, len1, factor2, len2, length);
	if (result == NULL)
		exit(98);
	print_result(result, length);
	return (0);
}

