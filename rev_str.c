#include "main.h"

/**
 * rev_str - function reverses string
 * @ptr: arg list
 * @print: memory buffer
 * @arr: just there
 * Return: 0
 */

int rev_str(va_list ptr, buffer_t *print, int arr)
{
	int k;
	char d, *str;

	str = va_arg(ptr, char *);
	k = 0;
	while (str[k] != 0)
	{
		k++;
	}
	k--;
	while (k >= 0)
	{
		d = str[k];
		_memcpy(print, &d, 1);
		k--;
	}
	return (arr);
}


/**
 * rot13 - function reverses string
 * @ptr: arg list
 * @print: memory buffer
 * @arr: just there
 * Return: 0
 */


int rot13(va_list ptr, buffer_t *print, int arr)
{
	char d, *str;
	int i, j;
	char let[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char rot[53] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	str = va_arg(ptr, char *);
	i = 0;
	while (str[i])
	{
		if ((str[i] >= 65 && str[i] < 91) || (str[i] >= 97 && str[i] < 123))
		{
			for (j = 0; j < 52; j++)
			{
				if (str[i] == let[j])
				{
					d = rot[j];
					_memcpy(print, &d, 1);
					break;
				}
			}
		}
		else
		{
			d = str[i];
			_memcpy(print, &d, 1);
		}
		i++;
	}
	return (arr);
}
