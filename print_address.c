#include "main.h"

/**
 * do_print_address - print binary
 * @i: param
 * @base: param
 * @map: param
 * @w: param
 * @buffer: param
 * @pos: param
 */
void do_print_address(unsigned long i, int base, char *map,
			int *w, char *buffer, int *pos)
{
	if (i == 0)
		return;
	do_print_address(i / base, base, map, w, buffer, pos);
	(*w) += write_buffer(buffer, pos);
	buffer[(*pos)++] = map[(i % base)];
}


/**
 * print_address - print binary
 * @ap: param
 * @arg: param
 * @buffer: param
 * @pos: param
 *
 * Return: int
 */
int print_address(va_list ap, char arg, char *buffer, int *pos)
{
	int w = 0;
	unsigned long i = va_arg(ap, unsigned long);

	if (i == 0)
	{
		w = write_buffer(buffer, pos);
		buffer[(*pos)++] = '(';
		w += write_buffer(buffer, pos);
		buffer[(*pos)++] = 'n';
		w += write_buffer(buffer, pos);
		buffer[(*pos)++] = 'i';
		w += write_buffer(buffer, pos);
		buffer[(*pos)++] = 'l';
		w += write_buffer(buffer, pos);
		buffer[(*pos)++] = ')';
		return (w);
	}
	w += write_buffer(buffer, pos);
	buffer[(*pos)++] = '0';
	w += write_buffer(buffer, pos);
	buffer[(*pos)++] = 'x';
	do_print_address(i, 16, "0123456789abcdef", &w, buffer, pos);
	return (w);
}
