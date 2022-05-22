#include "main.h"
#include <stdlib.h>

int convert_p(va_list ptr, buffer_t *printer)
{
	unsigned long int con;

	con = va_arg(ptr, unsigned long int);
	hex_lower(con, printer);
	return (0);
}


int hex_lower(unsigned long int x, buffer_t *print)
{
	unsigned long int y;
	int i, j, tmp, *arr;
	char *hex = "0x";

	y = x;
	j = 0;
	while (y > 0)
	{
		y = y / 16;
		j++;
	}
	arr = malloc(sizeof(unsigned long int) * j);
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
	_memcpy(print, hex, 2);
	convert_p_hex(i, arr, print);
	free(arr);
	return (0);
}

void convert_p_hex(int i, int *arr, buffer_t *print)
{
	char *hex = "abcdef";
	int num[6] = {10, 11, 12, 13, 14, 15};
	char m;
	int j;

	while (i >= 0)
	{
		if (arr[i] < 10)
		{
			m = arr[i] + '0';
			_memcpy(print, &m, 1);
		}
		else
		{
			for (j = 0; j < 6; j++)
			{
				if (arr[i] == num[j])
				{
					m = hex[j];
					_memcpy(print, &m, 1);
				}
			}
		}
		i--;
	}
}
