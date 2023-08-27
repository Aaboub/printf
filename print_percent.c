#include "main.h"

/**
 * print_percent - writes character
 * @ap: param
 * @arg: param
 * @buffer: param
 * @pos: param
 *
 * Return: int
 */
int print_percent(va_list ap, char arg, char *buffer, int *pos)
{
	int w;

	UNUSED(ap);
	UNUSED(pos);
	w = write_buffer(buffer, pos);
	buffer[*pos] = arg;
	(*pos)++;
	return (w);
}
