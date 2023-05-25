#include "shell.h"

/**
 * _memset - a function to fill memory with a constant byte
 * @s: a pointer to the memory area
 * @b: the byte to fill with
 * @n: number of bytes of bytes to be filled
 * Return: a pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}

/**
 * ffree - a funtion that frees a string of strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **str = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
		free(*pp++);
	free(str);
}

/**
 * _realloc - a function that reallocates a block of memory
 * @ptr: pointer to previous block
 * @old_size: size of previous block
 * @new_size: size of new block
 * Return: pointer to da old block
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *pointer;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	pointer = malloc(new_size);
	if (!pointer)
		return (NULL);

	if (old_size > new_size)
		old_size = new_size;
	while (old_size--)
		pointer[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (pointer);
}
/**
 * bfree - frees a pointer and NULLs the address
 * @ptr: address of the pointer to free
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

