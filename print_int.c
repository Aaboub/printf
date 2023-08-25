#include "main.h"

/**
 * do_print_int - recursion function to print int
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
        print_char( abs(i) + '0');
        (*sum)++;
    }
}

/**
 * print_int - entry point for do_print
 * @i: param
 * @sum: param
 */
void print_int(int i, int *sum) {
    if (i < 0)
    {
        print_char('-');
        (*sum)++;
    }
    do_print_int(i, sum);
}