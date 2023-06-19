#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - free memory block "dog"
 * @d: pointer to struct "dog"
 */


void free_dog(dog_t *d)
{
	if (d != NULL)
	{
		free(d->name);
		free(d->owner);

		free(d);
	}
}
