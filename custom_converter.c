#include <stdarg.h>
#include <stdlib.h>
#include "main.h"

/**
 * custom_u - custom for unsigned int
 * @ptr: arg list
 * @print: memory buffer
 * @opp: just there
 * Return: 0
 */


int custom_u(va_list ptr, buffer_t *print, int opp)
{
	char d;
	unsigned int temp, i, j, *arr;
	unsigned int num, mun = 0;

	num = (unsigned int)va_arg(ptr, int);
	if (num == 0)
	{
		d = '0';
		_memcpy(print, &d, 1);
		return (0);
	}
	mun = num;
	j = 0;
	while (num > 0)
	{
		num = num / 10;
		j++;
	}
	arr = malloc(sizeof(unsigned int) * (j + 1));
	if (arr == NULL)
		return (1);
	i = 0;
	while (mun > 0)
	{
		temp = mun % 10;
		arr[i] = temp;
		mun = mun / 10;
		i++;
	}
	if (opp > 0 && (unsigned int)opp > j)
		print->buffer -= j + 1;
	i--;
	while (i < j)
	{
		d = arr[i] + '0';
		_memcpy(print, &d, 1);
		i--;
	}
	free(arr);
	return (0);
}

/**
 * custom_o - function customize to octal
 * @ptr: arg list
 * @print: memory buffer
 * @opp: just there
 * Return: 0
 */

int custom_o(va_list ptr, buffer_t *print, int opp)
{
	char d;
	unsigned int i, j, temp, *arr;
	unsigned int num, same;

	num = (unsigned int)va_arg(ptr, int);
	if (num == 0)
	{
		d = '0';
		_memcpy(print, &d, 1);
		return (0);
	}
	same = num;
	i = 0;
	while (num > 0)
	{
		num = num / 8;
		i++;
	}
	arr = malloc(sizeof(unsigned int) * i);
	if (arr == NULL)
		return (-1);
	j = 0;
	while (same > 0)
	{
		temp = same % 8;
		arr[j] = temp;
		same = same / 8;
		j++;
	}
	if (opp > 0 && (unsigned int)opp > i)
		print->buffer -= i + 1;
	j--;
	while (j < i)
	{
		d = arr[j] + '0';
		_memcpy(print, &d, 1);
		j--;
	}
	free(arr);
	return (0);
}


/**
 * custom_x - function customizes to hexdecimal
 * @ptr: arg list
 * @print: memory buffer
 * @opp: just there
 * Return: 0
 */


int custom_x(va_list ptr, buffer_t *print, int opp)
{
	char d;
	int i, j, temp, *arr;
	unsigned int num, same;

	num = (unsigned int)va_arg(ptr, int);
	if (num == 0)
	{
		d = '0';
		_memcpy(print, &d, 1);
		return (0);
	}
	if (num == 0 &&  print->start[print->len - 2] == '0' &&  print->start
	    [print->len - 1] == 'x')
	{
		print->start[print->len - 1] = 0;
	}
	same = num;
	j = 0;
	while (num > 0)
	{
		num = num / 16;
		j++;
	}
	arr = malloc(sizeof(int) * j);
	if (arr == NULL)
		return (1);
	i = 0;
	while (same > 0)
	{
		temp = same % 16;
		arr[i] = temp;
		same = same / 16;
		i++;
	}
	if (opp > 0 && opp > j)
		print->buffer -= j + 1;
	i--;
	convert_p_hex(i, arr, print);
	return (0);
}


/**
 * convert_hex_upper - function reverses string
 * @i: arg list
 * @print: memory buffer
 * @arr: array that stores data
 */


void convert_hex_upper(int i, int *arr, buffer_t *print)
{
	char *hex = "ABCDEF";
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

/**
 * custom_X - function converts to hexdecimal
 * @ptr: arg list
 * @print: memory buffer
 * @opp: just there
 * Return: 0
 */

int custom_X(va_list ptr, buffer_t *print, int opp)
{
	char d;
	int i;
	int j, temp, *arr;
	unsigned int num, same;

	num = (unsigned int)va_arg(ptr, int);
	if (num == 0)
	{
		d = '0';
		_memcpy(print, &d, 1);
		return (0);
	}
	if (num == 0 &&  print->start[print->len - 2] == '0' &&  print->start
	    [print->len - 1] == 'X')
	{
		print->start[print->len - 1] = 0;
	}
	same = num;
	j = 0;
	while (num > 0)
	{
		num = num / 16;
		j++;
	}
	arr = malloc(sizeof(int) * j);
	if (arr == NULL)
		return (1);
	i = 0;
	while (same > 0)
	{
		temp = same % 16;
		arr[i] = temp;
		same = same / 16;
		i++;
	}
	if (opp > 0 && opp > j)
		print->buffer -= j + 1;
	i--;
	convert_hex_upper(i, arr, print);
	return (opp);
}
