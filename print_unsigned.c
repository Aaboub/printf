#include "main.h"

/**
 * do_print_unsigned - print unsigned
 * @i: param
 * @sum: param
 */
void do_print_unsigned(unsigned int i, int *sum)
{
	if (i >= 10)
	{
		do_print_unsigned((i / 10), sum);
		do_print_unsigned(i % 10, sum);
	}
	else
	{
		put_char(i + '0');
		(*sum)++;
	}
}

/**
 * print_nsigned - entry point for do_print
 * @ap: param
 * @arg: param
 *
 * Return: int
 */
int print_nsigned(va_list ap, int arg)
{
	int sum = 0;
	unsigned int i = va_arg(ap, unsigned int);

	UNUSED(arg);
	do_print_unsigned(i, &sum);
	return (sum);
}
