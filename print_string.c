#include "main.h"

/**
 * do_print_string - do print
 * @s: param
 *
 * Return: int
 */
int do_print_string(char *s)
{
	int i = 0;

	if (s)
	{
		while (*s)
		{
			put_char(*s);
			s++;
			i++;
		}
		return (i);
	}
	return (do_print_string("(null)"));
}

/**
 * print_string - Entry
 * @ap: param
 * @arg: param
 *
 * Return: int
 */
int print_string(va_list ap, int arg)
{
	char *s = va_arg(ap, char*);

	UNUSED(arg);
	return (do_print_string(s));
}
