#include "main.h"

/**
 * print_char - writes character
 * @ap: param
 *
 */
int print_char(va_list ap, int arg)
{
	return put_char(va_arg(ap, int));
}
