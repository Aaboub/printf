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
        put_char(i+ '0');
        (*sum)++;
    }
}

/**
 * print_unsigned - entry point for do_print
 *
 * @ap: param
 * @arg: param
 */
int print_unsigned(va_list ap, int arg)
{
    int sum = 0;
    unsigned int i = va_arg(ap, unsigned int);

    do_print_unsigned(i, &sum);
    return sum;
}
