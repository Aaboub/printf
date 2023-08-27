#include "main.h"

/**
 * do_print_string - do print
 * @s: param
 * @buffer: param
 * @pos: param
 *
 * Return: int
 */
int do_print_string(char *s, char *buffer, int *pos)
{
	int w = 0;

	if (s)
	{
		while (*s)
		{
			w += write_buffer(buffer, pos);
			buffer[*pos] = *s;
			(*pos)++;
			s++;
		}
		return (w);
	}
	return (do_print_string("(null)", buffer, pos));
}

/**
 * print_string - Entry
 * @ap: param
 * @arg: param
 * @buffer: param
 * @pos: param
 *
 * Return: int
 */
int print_string(va_list ap, char arg, char *buffer, int *pos)
{
	char *s = va_arg(ap, char*);

	UNUSED(arg);
	return (do_print_string(s, buffer, pos));
}
