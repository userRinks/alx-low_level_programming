#include <stdio.h>

/**
 * main - run crack_password
 * Return: 0
 */

void crack_password(void);

int main(void)
{
	crack_password();
	return (0);
}


/**
 * crack_password - crack the 4-digit password and print it
 * Return: 0
 */

void crack_password(void)
{
	int i = 0;
	int operand;

	char password[] = "Foob";

	while (i <= 3)
	{
		operand = i << 3;
		int shifted = 0x46c6f48 >> operand;
		int masked = 0xff & shifted;

		password[i] = masked;
		i++;
	}

	printf("%s\n", password);
}
