#include "main.h"

/**
 * leet - transform to Leet(1337) internet language
 * @s: char array string type
 * Return: s in Leet
 */

char *leet(char *s)
{
	int x, y;
	char s1[] = "aeotl";
	char l1[] = "AEOTL";	/*s1 capitalized*/
	char s2[] = "43071";	/*l1 translated to Leet*/

	for (x = 0; s[x] != '\0'; x++)
	{
		for (y = 0; y < 5; y++)
		{
			if (s[x] == s1[y] || s[x] == l1[y])
			{
				s[x] = s2[y];
				break;
			}
		}
	}
	return (s);
}
