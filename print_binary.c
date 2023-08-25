#include "main.h"

/**
 * print_binary - print binary
 * @i: param
 * @sum: param
 */
void print_binary(int i, int *sum) {
    if(i != 0)
    {
        print_binary(i / 2, sum);
        print_char((i % 2) + '0');
        (*sum)++;
    }
}