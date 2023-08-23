#include "main.h"

/**
 * print_string - Entry
 *
 * @s: param
 *
 * Return: len
 */
int print_string(const char *s)
{
	int i = 0;

	if (s)
	{
		while (*s)
		{
			_putchar(*s);
			s++;
			i++;
		}
		return (i);
	}
	return (print_string("(null)"));
}
