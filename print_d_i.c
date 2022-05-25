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
	char d, c = '-';
	long int res = 0, i;

	res = va_arg(ptr, int);
	if (res == 0)
	{
		d = '0';
		_memcpy(print, &d, 1);
		return (0);
	}
	if (res < 0)
	{
		res = res * -1;
		i = 1;
		if (print->start[print->len - i] == '+')
		{
			print->start[print->len - i] = '-';
		}
		else if (print->start[print->len - i] == ' ')
		{
			print->start[print->len - i] = '-';
		}
		else
			_memcpy(print, &c, 1);
	}
	out_array(res, print, arr);

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
		i = 1;
		if (print->start[print->len - i] == '+')
		{
			print->start[print->len - i] = '-';
		}
		else if (print->start[print->len - i] == ' ')
		{
			print->start[print->len - i] = '-';
		}
		else
			_memcpy(print, &c, 1);
	}
	else
	{
		re = re;
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
			if (print->start[print->len - i] == '+')
			{
				print->start[print->len - i] = '-';
			}
			else if (print->start[print->len - i] == ' ')
			{
				print->start[print->len - i] = '-';
			}
			else
				_memcpy(print, &c, 1);
	}
	else
	{
		re = re;
	}
	return (re);
}


/**
 * check_zero - check for zero
 * @res: params
 * Return: 0
 */

int check_zero(long int res, buffer_t *print)
{
	char d;
	if (res == 0)
	{
		d = '0';
		_memcpy(print, &d, 1);
		return (0);
	}
	return (0);
}
