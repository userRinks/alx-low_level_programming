#include <stdio.h>
#include <math.h>

/* Addition */
int add(int a, int b)
{
	return (a + b);
}

/* Subtraction */
int sub(int a, int b)
{
	return (a - b);
}

/* Multiplication */
int mul(int a, int b)
{

	return (a * b);
}

/* Division */
int div(int a, int b)
{
	if (b == 0)
	{
		printf("Error: Division by zero");
		return (-1);
	}
	return (a / b);
}

/* Modulo */
int mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error: Modulo by zero");
		return (-1);
	}
	return (a % b);
}
