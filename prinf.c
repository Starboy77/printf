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

	if (format == NULL || print == NULL)
		return (-1);
	va_start(ptr, format);
	while (format[i])
	{
		if (format[i] != '%')
			tot += _memcpy(print, &format[i], 1);
		else
		{
			if (format[i] == '%' && format[i + 1] == 0)
				return (-1);
			else if (format[i] == '%' && format[i + 1] != 's' &&
format[i + 1] != 'c' && format[i + 1] != 'd' && format[i + 1] != 'i' &&
format[i + 1] != 'u' && format[i + 1] != 'o' && format[i + 1] != 'x' &&
format[i + 1] != 'X' && format[i + 1] != 'p' && format[i + 1] != 'b' &&
format[i + 1] != 'S' && format[i + 1] != 'r' && format[i + 1] != 'R' &&
format[i + 1] != '+' && format[i + 1] != 'h' && format[i + 1] != '#' &&
format[i + 1] != '%' && format[i + 1] != ' ')
			{
				j = not_spec(i, format, print);
				i = j + 1;
				continue;
			}
			else
			{
				j = flag(i, format, print);
				arr = width(i, format);
				spec(format[i + j])(ptr, print, arr);
				i = i + j + 1;
				continue;
			}
		}
		i++;
	}
	final = print_end(print, ptr, final);
	return (final);
}


/**
 * print-end - end printf function
 * @print: memory buffers
 * @ptr: va args
 * @final: int parameter
 * Return: 0
 */


int print_end(buffer_t *print, va_list ptr, int final)
{
	va_end(ptr);
	write(1, print->start, print->len);
	final = print->len;
	free_buf(print);
	return (final);
}


/**
 * not_spec - flag function
 * @i: arg list
 * @print: memory buffer
 * @format: format string
 * Return: 0
 */


int not_spec(int i, const char *format, buffer_t *print)
{
	if (format[i + 1] != 's' && format[i + 1] != 'c' && format[i + 1] != 'd'
	    && format[i + 1] != 'i' && format[i + 1] != 'u' && format[i + 1] !=
	    'o' && format[i + 1] != 'x' && format[i + 1] != 'X' && format[i + 1]
	    != 'p' && format[i + 1] != 'b' && format[i + 1] != 'S' &&
	    format[i + 1] != 'r' && format[i + 1] != 'R' && format[i + 1] != 0
	    && format[i + 1] != '+' && format[i + 1] != 'h')
	{
		_memcpy(print, &format[i], 1);
		_memcpy(print, &format[i + 1], 1);
	}
	return (i + 1);
}
