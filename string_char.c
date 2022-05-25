#include "main.h"

/**
 * string - function reverses string
 * @ptr: arg list
 * @print: memory buffer
 * @arr: just there
 * Return: 0
 */

int string(va_list ptr, buffer_t *print, int arr)
{
	char *str, *d;

	str = va_arg(ptr, char *);
	if (arr > 0 && arr > _strlen(str))
	{
		print->buffer -= _strlen(str);
		print->len -= _strlen(str);
		_memcpy(print, str, _strlen(str));
		return (0);
	}
	if (arr > 0 && arr < _strlen(str))
	{
		print->buffer -= arr;
		print->len -= arr;
		_memcpy(print, str, _strlen(str));
		return (0);
	}
	if (str == 0)
	{
		d = "(null)";
		_memcpy(print, d, 6);
	}
	else
	{
		_memcpy(print, str, _strlen(str));
	}
	return (0);
}

/**
 * cha - function prints char
 * @ptr: arg list
 * @print: memory buffer
 * @arr: just there
 * Return: 0
 */

int cha(va_list ptr, buffer_t *print, int arr)
{
	char cha;

	cha = (char)va_arg(ptr, int);
	if (arr > 0 && arr > 1)
	{
		print->buffer -= 1;
		print->len -= 1;
	}
	_memcpy(print, &cha, 1);
	return (0);
}

/**
 * modulo - function escapes a modulo
 * @ptr: arg list
 * @print: memory buffer
 * @arr: just there
 * Return: 0
 */

int modulo(va_list ptr __attribute__ ((unused)), buffer_t *print, int arr)
{
	char cha;

	cha = '%';
	_memcpy(print, &cha, 1);
	return (arr);
}
