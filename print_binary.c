#include "main.h"

/**
 * print_binary - print binary
 * @i: param
 * @base: param
 * @sum: param
 */
void do_print_binary(long i, int base, int *sum)
{
    if (i == 0)
        return;
    do_print_binary(i / base, base, sum);
    print_char((i % base) + '0');
    (*sum)++;
}


/**
 * print_binary - print binary
 * @i: param
 * @sum: param
 */
void print_binary(long i, int base, int *sum)
{
    if (i == 0)
    {
        print_char('0');
        (*sum)++;
        return;
    }
    if (i < 0)
    {
        print_char('-');
        (*sum)++;
    }
    do_print_binary(i < 0 ? -i : i, base, sum);
}
