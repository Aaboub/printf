#include "main.h"

/**
 * do_print_string - do print
 * @s: param
 * @buffer: param
 * @pos: param
 *
 * Return: int
 */
int do_print_string(char *s, char arg, char *buffer, int *pos)
{
	int w = 0;
	char map[] = "0123456789ABCDEF";

	if (s)
	{
		while (*s)
		{
			w += write_buffer(buffer, pos);
			if (arg == 'S' && is_non_printable(*s))
			{
				buffer[(*pos)++] = '\\';
				w += write_buffer(buffer, pos);
				buffer[(*pos)++] = 'x';
				w += write_buffer(buffer, pos);
				buffer[(*pos)++] = map[*s / 16];
				w += write_buffer(buffer, pos);
				buffer[(*pos)++] = map[*s % 16];
				s++;
			}
			else
			{
				buffer[(*pos)++] = *s;
				s++;
			}
		}
		return (w);
	}
	return (do_print_string("(null)", arg, buffer, pos));
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

	return (do_print_string(s, arg, buffer, pos));
}

/**
 * is_non_printable - printable?
 * @i: param
 *
 * Return: printable?
 */
bool is_non_printable(char i)
{
	return (i < 32 || i >= 127);
}
