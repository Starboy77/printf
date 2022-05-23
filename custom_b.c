#include "main.h"
#include <stdarg.h>
#include <stdlib.h>

/**
 * custom_b - function reverses string
 * @ptr: arg list
 * @print: memory buffer
 * @opp: just there
 * Return: 0
 */


int custom_b(va_list ptr, buffer_t *print, int opp)
{
	char d;
	int j = 0, *bin;
	unsigned int num;

	opp = 0;
	opp = j;
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
	return (opp);
}
