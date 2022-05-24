#include "main.h"

unsigned int _memcpy(buffer_t *print, const char *src, unsigned int n);
void free_buf(buffer_t *print);
buffer_t *init_buffer(void);

/**
 * _memcpy - Copies n bytes from memory area src to
 *           the buffer contained in a buffer_t struct.
 * @print: A buffer_t struct.
 * @src: A pointer to the memory area to copy.
 * @n: The number of bytes to be copied.
 *
 * Return: The number of bytes copied.
 */
unsigned int _memcpy(buffer_t *print, const char *src, unsigned int n)
{
	unsigned int index;

	for (index = 0; index < n; index++)
	{
		*(print->buffer) = *(src + index);
		(print->len)++;
		(print->final)++;

		if (print->final == 1024)
		{
			write(1, print->start, print->len);
			print->buffer = print->start;
			print->final = 0;
		}

		else
			(print->buffer)++;
	}
	return (n);
}

/**
 * free_buf - Frees a buffer_t struct.
 * @print: The buffer_t struct to be freed.
 */
void free_buf(buffer_t *print)
{
	free(print->start);
	free(print);
}

/**
 * init_buffer - Initializes a variable of struct type buffer_t.
 *
 * Return: A pointer to the initialized buffer_t.
 */
buffer_t *init_buffer(void)
{
	buffer_t *print;

	print = malloc(sizeof(buffer_t));
	if (print == NULL)
		return (NULL);

	print->buffer = malloc(sizeof(char) * 1024);
	if (print->buffer == NULL)
	{
		free(print);
		return (NULL);
	}

	print->start = print->buffer;
	print->len = 0;
	print->final = 0;

	return (print);
}
