#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 *main - generates random valid passes
 *
 *Return: always 0 (Success)
 *
 *srand: initialize random generator
 */

int main(void)
{
	int i, sum, x;
	int validpass[100];

	sum = 0;

	srand(time(NULL));

	for (i = 0; i < 100; i++)
	{
		validpass[i] = rand() % 100;
		sum += (validpass[i] + '0');
		putchar(validpass[i] + '0');
		if  ((1738 - sum) - '0' < 100)
		{
			x = 1738 - sum - '0';
			sum += x;
			putchar(x + '0');
			break;
		}
	}

	return (0);
	
}
