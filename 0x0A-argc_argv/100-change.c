#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * main - print minimum coins to get change for input
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1
 */

int main(int argc, char *argv[])
{
	int money, coins;

	coins = 0;
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	money = atoi(argv[1]);
	if (money < 0)
	{
		printf("%d\n", 0);
		return (0);
	}
	if (money % 25 >= 0)
	{
		coins += money / 25;
		money = money % 25;
	}
	if (money % 10 >= 0)
	{
		coins += money / 10;
		money = money % 10;
	}
	if (money % 5 >= 0)
	{
		coins += money / 5;
		money = money % 5;
	}
	if (money % 2 >= 0)
	{
		coins += money / 2;
		money = money % 2;
	}
	if (money % 1 >= 0)
	{
		coins += money / 1;
	}
	printf("%d\n", coins);
	return (0);
}
