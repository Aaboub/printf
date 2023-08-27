#include "main.h"

/**
 * print_char - writes character
 * @ap: param
 * @arg: param
 * @buffer: param
 * @pos: param
 *
 * Return: int
 */
int print_char(va_list ap, char arg, char *buffer, int *pos)
{
	int w;

	UNUSED(arg);
	w = write_buffer(buffer, pos);
	buffer[(*pos)++] = va_arg(ap, int);
	return (w);
}
