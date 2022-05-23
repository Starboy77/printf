#include <stdarg.h>
#include "main.h"
#include <unistd.h>
#include <stdlib.h>

/**
 * print_d_i - function prints the d and i specifier
 * @ptr: arg list
 * @print: memory buffer
 * @arr: just there
 * Return: 0
 */


int print_d_i(va_list ptr, buffer_t *print, int arr)
{
	long int res = 0;

	if (print->start[print->len - 1] == 'h')
	{
		print->start[print->len - 1] = 0;
		(print->buffer) -= 0;
		res = va_arg(ptr, int);
		res = (short)res;
		res = ret(res, print);
		out_array(res, print, arr);
	}
	else if (print->start[print->len - 1] == 'l')
	{
		print->start[print->len - 1] = 0;
		(print->buffer) -= 2;
		res = (long int)va_arg(ptr, long int);
		res = (long int)ret(res, print);
		out_array(res, print, arr);
	}
	else
	{
		res = va_arg(ptr, int);
		(print->buffer)--;
		res = ret_none(res, print);
		out_array(res, print, arr);
	}
	return (0);
}


/**
 * ret - function reverses string
 * @re: arg list
 * @print: memory buffer
 * Return: 0
 */

long int ret(int re, buffer_t *print)
{
	int i;
	char c = '-';

	if (re < 0)
	{
		re = re * -1;
		i = 2;
		while (print->start[print->len - i])
		{
			if (print->start[print->len - i] == '+')
			{
				print->start[print->len - i] = 0;
				(print->buffer)--;
				_memcpy(print, &c, 1);
				i++;
				break;
			}
			else if (print->start[print->len - i] == ' ')
			{
				print->start[print->len - i] = 0;
				(print->buffer)--;
				_memcpy(print, &c, 1);
				i++;
				break;
			}
			else if (print->start[print->len - i] == '-')
			{
				print->start[print->len - i] = '-';
				(print->buffer)--;
				i++;
				break;
			}
			i++;
		}
	}
	return (re);
}

/**
 * out_array - function output array
 * @res: parametr of type int
 * @print: memory buffer
 * @opp: integer parameter
 * Return: 0
 */

int out_array(int res, buffer_t *print, int opp)
{
	long int ser;
	char d;
	int j = 0, m = 0, temp = 0, *arr;

	ser = res;
	m = 0;
	while (res > 0)
	{
		res = res / 10;
		m++;
	}
	arr = malloc(sizeof(int) * m);
	if (arr == NULL)
		return (1);
	j = 0;
	while (ser > 0)
	{
		temp = ser % 10;
		ser = ser / 10;
		arr[j] = temp;
		j++;
	}
	if (opp > 0 && opp > m)
		print->buffer -= m + 1;
	m--;
	while (m >= 0)
	{
		d = arr[m] + '0';
		_memcpy(print, &d, 1);
		m--;
	}
	free(arr);
	return (0);
}


/**
 * ret_none - function reverses string
 * @re: arg list
 * @print: memory buffer
 * Return: 0
 */


int ret_none(int re, buffer_t *print)
{
	int i;
	char c = '-';

	if (re < 0)
	{
		re = re * -1;
		i = 1;
		while (print->start[print->len - i])
		{
			if (print->start[print->len - i] == '+')
			{
				print->start[print->len - i] = 0;
				(print->buffer)--;
				_memcpy(print, &c, 1);
				i++;
				break;
			}
			else if (print->start[print->len - i] == ' ')
			{
				print->start[print->len - i] = 0;
				(print->buffer)--;
				_memcpy(print, &c, 1);
				i++;
				break;
			}
			else if (print->start[print->len - i] == '-')
			{
				print->start[print->len - i] = '-';
				(print->buffer)--;
				i++;
				break;
			}
			i++;
		}
	}
	return (re);
}
