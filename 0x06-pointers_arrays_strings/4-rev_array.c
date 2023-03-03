#include "main.h"
/**
 * reverse_array - reverse a int array
 * @a: pointer
 * @n: array length
 * bruh: variable
 * Return: void
*/

void reverse_array(int *a, int n)
{
	int i = 0, bruh;

	for (bruh = n / 2; bruh > 0; bruh--, i++)
	{
		a[n - i - 1]	 += a[i];
		a[i]		 = a[n - i - 1] - a[i];
		a[n - i - 1]	 = a[n - i - 1] - a[i];
	}
}
