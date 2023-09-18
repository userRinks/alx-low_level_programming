#include "main.h"

/**
 * _isupper - checks for uppercase character
 * @c:  integer type number
 * Return:	1 if uppercase character
 *		0 if else
 */
int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
