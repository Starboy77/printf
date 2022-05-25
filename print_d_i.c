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
	long int res = 0;
	unsigned long int n;

	res = va_arg(ptr, int);
	n = res;
	if (res == 0)
	{
		d = '0';
		_memcpy(print, &d, 1);
		return (0);
	}
	if (res < 0)
	{
		n = -res;
		if (print->start[print->len - 1] == '+')
		{
			print->start[print->len - 1] = '-';
		}
		else if (print->start[print->len - 1] == ' ')
		{
			print->start[print->len - 1] = '-';
		}
		else
			_memcpy(print, &c, 1);
	}
	out_array(n, print, arr);
	return (arr);
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
 * @n: parametr of type int
 * @print: memory buffer
 * @opp: integer parameter
 * Return: 0
 */

int out_array(unsigned int n, buffer_t *print, int opp)
{
	char d;
	long int i, j, l, *arry;
	unsigned int m;

	m = n;
	j = 0;
	while (m > 0)
	{
		m = m / 10;
		j++;
	}
	arry = malloc(sizeof(long int) * j);
	if (arry == NULL)
		return (1);
	i = 0;
	while (n > 0)
	{
		l = n % 10;
		arry[i] = l;
		n = n / 10;
		i++;
	}
	if (opp > 0 && opp > i)
	{
		print->buffer -= i;
		print->len -= i;
	}
	if (opp > 0 && opp < i)
	{
		print->buffer -= opp;
		print->len -= opp;
	}
	i--;
	while (i >= 0)
	{
		d = arry[i] + '0';
		_memcpy(print, &d, 1);
		i--;
	}
	free(arry);
	return (opp);
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
		re = (unsigned int)re;
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
 * @print: buffer memory
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
