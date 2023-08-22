#include "main.h"

/**
 * print_string - Entry
 *
 * @s: param
 *
 * Return: len
 */
int print_string(char *s)
{
	int len;
	int i;

	if (s)
	{
		len = (int)strlen(s);
		for (i = 0; i < len; i++)
		{
			_putchar(*(s + i));
		}
        return (len);
	}
    return (0);
}
