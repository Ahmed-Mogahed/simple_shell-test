#include "shelly.h"

/**
 * _calloc - Allocate memory and initialize it to 0
 * @size: Number of bytes to allocate
 * Return: Pointer to allocated memory (Success), NULL (Failure)
 */
void *_calloc(unsigned int size)
{
	void *ptr;
	char *ch_ptr;
	unsigned int i;

	if (size == 0)
		return (NULL);

	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);

	ch_ptr = (char *)ptr;
	for (i = 0; i < size; i++)
		ch_ptr[i] = 0;

	return (ptr);
}

/**
 * _realloc - Reallocate memory block
 * @ptr: Pointer to previously allocated memory
 * @old_size: Old size in bytes
 * @new_size: New size in bytes
 * Return: Pointer to reallocated memory (Success), NULL (Failure)
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;
	char *ch_ptr, *old_ch_ptr;
	unsigned int i;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
			return (NULL);
		return (new_ptr);
	}

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	ch_ptr = (char *)new_ptr;
	old_ch_ptr = (char *)ptr;

	for (i = 0; i < old_size && i < new_size; i++)
		ch_ptr[i] = old_ch_ptr[i];

	free(ptr);
	return (new_ptr);
}

/**
 * free_all - Free arrays of pointers
 * @input: Array of pointers to free
 * @line: Single pointer to free
 * Return: Void
 */
void free_all(char **input, char *line)
{
	unsigned int i;

	if (input)
	{
		for (i = 0; input[i] != NULL; i++)
			free(input[i]);
		free(input);
	}

	if (line)
		free(line);
}
