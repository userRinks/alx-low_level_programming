#include "function_pointers.h"

/**
 * print_name - Print name from a function pointer
 * @name: char
 * @f: function pointer that takes a string argument
 */

void print_name(char *name, void (*f)(char *))
{
	f(name);
}
