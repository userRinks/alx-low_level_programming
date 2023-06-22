#include "function_pointers.h"

/**
 * array_iterator - execute a func pointer on each element of an array
 * @array: array
 * @size: int
 * @action: function pointer
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	if (array && action)
	{
		while (size--)
		{
			action(*array++);
		}
}
