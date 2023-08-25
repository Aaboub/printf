#include "main.h"

/**
 * print_unsigned - entry point for do_print
 *
 * @i: param
 * @sum: param
 */
void print_unsigned(unsigned int i, int *sum)
{
    if (i >= 10)
    {
        print_unsigned((i / 10), sum);
        print_unsigned(i % 10, sum);
    }
    else
    {
        print_char(i+ '0');
        (*sum)++;
    }
}
