#include "main.h"

/**
 * do_print_base - print binary
 * @i: param
 * @base: param
 * @map: param
 * @w: param
 * @buffer: param
 * @pos: param
 */
void do_print_base(long i, int base, char *map, int *w, char *buffer, int *pos)
{
	if (i == 0)
		return;
	do_print_base(i / base, base, map, w, buffer, pos);
	(*w) += write_buffer(buffer, pos);
	buffer[*pos] = map[(i % base)];
	(*pos)++;
}


/**
 * print_base - print binary
 * @ap: param
 * @base: param
 * @buffer: param
 * @pos: param
 *
 * Return: int
 */
int print_base(va_list ap, char base, char *buffer, int *pos)
{
	int w = 0;
	long i = va_arg(ap, long);

	if (i == 0)
	{
		w = write_buffer(buffer, pos);
		buffer[*pos] = '0';
		(*pos)++;
		return (w);
	}
	if (i < 0)
	{
		w = write_buffer(buffer, pos);
		buffer[*pos] = '-';
		(*pos)++;
	}

	switch (base)
	{
		case BASE_BINA:
			do_print_base(i < 0 ? -i : i, 2, "01", &w, buffer, pos);
			break;
		case BASE_OCTA:
			do_print_base(i < 0 ? -i : i, 8, "01234567", &w, buffer, pos);
			break;
		case BASE_HEXA_S:
			do_print_base(i < 0 ? -i : i, 16, "0123456789abcdef", &w, buffer, pos);
			break;
		case BASE_HEXA_C:
			do_print_base(i < 0 ? -i : i, 16, "0123456789ABCDEF", &w, buffer, pos);
			break;
	}
	return (w);
}
