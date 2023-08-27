#include "main.h"

/**
 * do_print_int - recursion function to print int
 * @i: param
 * @w: param
 * @buffer: param
 * @pos: param
 */
void do_print_int(int i, int *w, char *buffer, int *pos)
{
	if (i >= 10 || i <= -10)
	{
		do_print_int((i / 10), w, buffer, pos);
		do_print_int(abs(i) % 10, w, buffer, pos);
	}
	else
	{
		(*w) += write_buffer(buffer, pos);
		buffer[(*pos)++] = abs(i) + '0';
	}
}

/**
 * print_int - entry point for print_arg
 * @ap: param
 * @arg: param
 * @buffer: param
 * @pos: param
 *
 * Return: int
 */
int print_int(va_list ap, char arg, char *buffer, int *pos)
{
	int w = 0;
	int i = va_arg(ap, int);

	UNUSED(arg);
	if (i < 0)
	{
		w = write_buffer(buffer, pos);
		buffer[(*pos)++] = '-';
	}
	do_print_int(i, &w, buffer, pos);
	return (w);
}
