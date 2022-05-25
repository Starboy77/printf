#include "main.h"
#include <stdlib.h>

/**
 * flag - flag function
 * @i: arg list
 * @print: memory buffer
 * @format: format string
 * Return: 0
 */

int flag(int i, const char *format, buffer_t *print)
{
	int j = 1, arr = 0;
	char plus = '0', *zero, *space = " ", blank = ' ', oct, *small;
	char *big;

	while (format[i + j] != '%' && format[i + j] != 'd' && format[i + j] !=
	       'i' && format[i + j] != 'u' && format[i + j] != 'x' && format[i +
									     j]
	       != 'X' && format[i + j] != 'o' && format[i + j] != 's' && format[
		       i + j] != 'c' && format[i + j] != 'b' && format[i + j] !=
	       'p' && format[i + j] != 'S' && format[i + j] != 'r'
	       && format[i + j] != 'R')
	{
		if (format[i + 1] == '0')
			zero = "0";
		if (format[i + j] >= 48 && format[i + j] < 58)
		{
			arr = (arr * 10) + (format[i + j] - '0');
		}
		if (format[i + j] == '+')
		{
			plus = '+';
			_memcpy(print, &plus, 1);

		}
		if (format[i + j] == ' ')
		{
			blank = ' ';
			_memcpy(print, &blank, 1);
		}
		if (format[i + j] ==  '#')
		{
			small = "0x";
			big = "0X";
			oct = '0';
		}
		j++;
	}
	flag_sub(arr, i, j, format, print, small, big, oct, space, zero);
	return (j);
}


/**
 * width -width specifier
 * @i: counter
 * @format: format string
 * Return: 0
 */


int width(int i, const char *format)
{
	int j = 1, arr = 0;

	while (format[i + j] != '%' && format[i + j] != 'd' && format[i + j] !=
	       'i' && format[i + j] != 'u' && format[i + j] != 'x' &&
	       format[i + j] != 'X' && format[i + j] != 'o' && format[i + j] !=
	       's' && format[i + j] != 'c' && format[i + j] != 'b' &&
	       format[i + j] != 'p' && format[i + j] != 'S' &&
	       format[i + j] != 'r' && format[i + j] != 'R')
	{
		if (format[i + j] >= 48 && format[i + j] < 58)
		{
			arr = (arr * 10) + (format[i + j] - '0');
		}
		j++;
	}
	return (arr);
}



/**
 * flag_sub - function used inside flag function above
 * @arr: arg list
 * @i: counter
 * @j: counter
 * @format: format string
 * @print: memory buffer
 * @small: small string
 * @big: big string
 * @oct: oct character
 * @space: space string
 * Return: 0
 */


int flag_sub(int arr, int i, int j, const char *format, buffer_t *print,
	     char *small, char *big, char oct, char *space, char *zero)
{
	char lng, shrt;

	if (arr > 0)
	{
		while (arr > 0)
		{
			if (zero != NULL)
			{
				_memcpy(print, zero, 1);
				arr--;
			}
			else
			{
				_memcpy(print, space, 1);
				arr--;
			}
		}
	}
	if (j > 1)
	{
		if (format[i + j] == 'x')
		{
			_memcpy(print, small, 2);
		}
		if (format[i + j] == 'X')
		{
			_memcpy(print, big, 2);
		}
		if (format[i + j] == 'o')
		{
			_memcpy(print, &oct, 1);
		}
	}
	if (format[i + j - 1] == 'h')
	{
		shrt = 'h';
		_memcpy(print, &shrt, 1);

	}
	if (format[i + j - 1] == 'l')
	{
		lng = 'l';
		_memcpy(print, &lng, 1);

	}
	return (0);
}
