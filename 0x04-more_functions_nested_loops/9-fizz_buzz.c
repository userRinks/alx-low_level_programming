#include <stdio.h>

/**
 * main - solve fizz buzz from numbers 1 to 100
 * Description: print and check numbers
 *	for multiples of 3, print Fizz
 *	for multiples of 5, print Buzz.
 *	for multiples of both 3 and 5, print FizzBuzz.
 * Return: 0
 */

int main(void)
{
	int i;

	i = 1;

	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			printf("FizzBuzz");
		else if (i % 3 == 0)
			printf("Fizz");
		else if (i % 5 == 0)
			printf("Buzz");
		else
			printf("%d", i);

		if (i != 100)
			printf(" ");
		i++;
	}
	printf("\n");

	return (0);
}
