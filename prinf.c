#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"


/**
 * _strlen - functions calcilate length of string
 * @s: string used
 * Return: 0
 */

int _strlen(char *s)
{
	int k = 0;

	while (s[k])
		k++;
	return (k);
}


/**
 * spec - function reverses string
 * @s: charcter to be compared
 * Return: function pointer
 */

int (*spec(char s))(va_list ptr, buffer_t *print, int arr)
{
	int i = 0;
	spec_t spec[] = {
		{'%', modulo},
		{'c', cha},
		{'s', string},
		{'d', print_d_i},
		{'i', print_d_i},
		{'b', custom_b},
		{'u', custom_u},
		{'o', custom_o},
		{'x', custom_x},
		{'X', custom_X},
		{'S', custom_S},
		{'p', convert_p},
		{'r', rev_str},
		{'R', rot13}
	};

	while (spec[i].s != s)
	{
		i++;
	}
	return (spec[i].func);
}

/**
 * _printf - prints string acoording to specifier and flags
 * @format: string to be formatted.
 * Return: 0
 */


int _printf(const char *format, ...)
{
	int arr = 0, i = 0, j = 0, final = 0, tot = 0;
	va_list ptr;
	buffer_t *print = init_buffer();

	va_start(ptr, format);

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			tot += _memcpy(print, &format[i], 1);
		}
		else
		{
			j = flag(i, format, print);
			arr = width(i, format);
			spec(format[i + j])(ptr, print, arr);
			i = i + j + 1;
			continue;
		}
		i++;
	}
	write(1, print->start, print->len);
	final = print->len;
	free_buf(print);
	return (final);
}
