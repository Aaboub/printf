#include "main.h"

/**
 * do_print_base - print binary
 * @i: param
 * @base: param
 * @map: param
 * @sum: param
 */
void do_print_base(long i, int base, char *map, int *sum)
{
	if (i == 0)
		return;
	do_print_base(i / base, base, map, sum);
	put_char(map[(i % base)]);
	(*sum)++;
}


/**
 * print_base - print binary
 * @ap: param
 * @base: param
 *
 * Return: int
 */
int print_base(va_list ap, int base)
{
	int sum = 0;
	long i = va_arg(ap, long);

	if (i == 0)
	{
		put_char('0');
		return (1);
	}
	if (i < 0)
	{
		put_char('-');
		sum++;
	}

	switch (base)
	{
		case BASE_BINA:
			do_print_base(i < 0 ? -i : i, 2, "01", &sum);
			break;
		case BASE_OCTA:
			do_print_base(i < 0 ? -i : i, 8, "01234567", &sum);
			break;
		case BASE_HEXA_S:
			do_print_base(i < 0 ? -i : i, 16, "0123456789abcdef", &sum);
			break;
		case BASE_HEXA_C:
			do_print_base(i < 0 ? -i : i, 16, "0123456789ABCDEF", &sum);
			break;
	}
	return (sum);
}
