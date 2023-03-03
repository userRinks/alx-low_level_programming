#include "main.h"

/**
 * *rot13 - encodes a string using ROT13.
 * @s: int type array pointer
 * Return: s encoded in ROT13
 */

char *rot13(char *s)
{
	int x, y;
	char eng[] =  "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (x = 0; s[x] != '\0'; x++)
	{
		for (y = 0; y < 54; y++)
		{
			if (((s[x] <= 'z' && s[x] >= 'a') || (s[x] <= 'Z' && s[x] >= 'A'))
			&& s[x] == eng[y])
			{
				s[x] = rot[y];
				break;
			}
		}
	}
	return (s);
}
