#include "main.h"

/**
 * print_char - writes character
 * @ap: param
 * @arg: param
 *
 * Return: int
 */
int print_char(va_list ap, int arg)
{
	UNUSED(arg);
	return (put_char(va_arg(ap, int)));
}
