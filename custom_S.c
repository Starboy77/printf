#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * hex_upper - convert to upper hex
 *
 * @x: character
 * @print: print
 *
 * Return: 0
 */

int hex_upper(int x, buffer_t *print)
{
	int y;
	int i, j, tmp, *arr;

	y = x;
	j = 0;
	while (y > 0)
	{
		y = y / 16;
		j++;
	}
	arr = malloc(sizeof(int) * j);
	if (arr == NULL)
		return (0);
	i = 0;
	while (x > 0)
	{
		tmp = x % 16;
		x = x / 16;
		arr[i] = tmp;
		i++;
	}
	i--;
	convert_hex_upper(i, arr, print);
	free(arr);
	return (0);

}

/**
 * custom_S - custom
 *
 * @ptr: print
 * @print: print func
 *
 * Return: 0
 */

int custom_S(va_list ptr, buffer_t *print)
{
	char *s, *d, *zero;
	int i;
	int cha;

	s = va_arg(ptr, char *);
	i = 0;
	while (s[i])
	{
		if ((s[i] > 0 && s[i] < 32) || (s[i] >= 127))
		{
			d = "\\x";
			_memcpy(print, d, 2);
			if (s[i] > 0 && s[i] < 16)
			{
				zero = "0";
				_memcpy(print, zero, 1);
				cha = s[i];
				hex_upper(cha, print);
			}
			else
			{
				cha = s[i];
				hex_upper(cha, print);
			}
			i++;
			continue;
		}
		else
			_memcpy(print, &s[i], 1);
		i++;
	}
	return (0);
}
