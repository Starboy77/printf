#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * custom_b - custom b
 *
 * @ptr: print
 * @print: print func
 *
 * Return: 0
 */

int custom_b(va_list ptr, buffer_t *print)
{
	char d;
	int j, *bin;
	unsigned int num;

	num = (unsigned int)va_arg(ptr, int);
	bin = malloc(num);
	if (bin == NULL)
		return (-1);
	j = 0;
	while (num > 0)
	{
		bin[j] = num % 2;
		num = num / 2;
		j++;
	}
	j--;
	while (j >= 0)
	{
		d = bin[j] + '0';
		_memcpy(print, &d, 1);
		j--;
	}
	free(bin);
	return (0);
}
