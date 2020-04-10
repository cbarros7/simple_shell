#include "SimpleShell.h"
/**
 * _realloc - Reallocates a space in memory
 * @ptr: The pointer with allocated size in memory
 * @new_size: The new size to realloc
 * Return: a newly allocated string
 */
void *_realloc(void *ptr, unsigned int new_size)
{
	char *str;

	if (ptr == NULL)
	{
		str = malloc(new_size);
		if (str == NULL)
			return (NULL);
		return (str);
	}
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	str = malloc(new_size);
	if (str == 0)
		return (NULL);


	free(ptr);
	return (str);
}
