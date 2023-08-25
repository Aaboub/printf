#include "main.h"

/**
 * print_base - print binary
 * @i: param
 * @base: param
 * @sum: param
 */
void do_print_base(long i, int base, char *map, int *sum)
{
    if (i == 0)
        return;
    do_print_base(i / base, base, map, sum);
    print_char(map[(i % base)]);
    (*sum)++;
}


/**
 * print_base - print binary
 * @i: param
 * @sum: param
 */
void print_base(long i, int base, int *sum)
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

    switch (base) {
        case BASE_BINA:
            do_print_base(i < 0 ? -i : i, 2, "01", sum);
            break;
        case BASE_OCTA:
            do_print_base(i < 0 ? -i : i, 8, "01234567", sum);
            break;
        case BASE_HEXA_S:
            do_print_base(i < 0 ? -i : i, 16, "0123456789abcdef", sum);
            break;
        case BASE_HEXA_C:
            do_print_base(i < 0 ? -i : i, 16, "0123456789ABCDEF", sum);
            break;
    }
}
