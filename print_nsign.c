#include "main.h"

/**
 * do_print_nsign - print unsigned
 * @i: param
 * @w: param
 * @buffer: param
 * @pos: param
 */
void do_print_nsign(unsigned int i, int *w, char *buffer, int *pos)
{
	if (i >= 10)
	{
		do_print_nsign((i / 10), w, buffer, pos);
		do_print_nsign(i % 10, w, buffer, pos);
	}
	else
	{
		(*w) = write_buffer(buffer, pos);
		buffer[(*pos)++] = i + '0';
	}
}

/**
 * print_nsign - entry point for print_arg
 * @ap: param
 * @arg: param
 * @buffer: param
 * @pos: param
 *
 * Return: int
 */
int print_nsign(va_list ap, char arg, char *buffer, int *pos)
{
	int w = 0;
	unsigned int i = va_arg(ap, unsigned int);

	UNUSED(arg);
	do_print_nsign(i, &w, buffer, pos);
	return (w);
}
