#include "main.h"

/**
 * do_print_int - recursion function to print int
 *
 * @i: param
 * @sum: param
 */
void do_print_int(int i, int *sum)
{
	if (i >= 10 || i <= -10)
	{
		do_print_int((i / 10), sum);
		do_print_int(abs(i) % 10, sum);
	}
	else
	{
		put_char(abs(i) + '0');
		(*sum)++;
	}
}

/**
 * print_int - entry point for do_print
 *
 * @ap: param
 */
int print_int(va_list ap, int arg)
{
    int sum = 0;
    int i = va_arg(ap, int);

    UNUSED(arg);
	if (i < 0)
	{
		put_char('-');
		sum++;
	}
	do_print_int(i, &sum);
    return sum;
}
