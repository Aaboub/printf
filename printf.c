#include "main.h"

/**
 * do_print - do actual printing
 *
 * @format: param
 * @i: param
 * @ap: param
 *
 * Return: number of printed chars
 */
int do_print(const char *format, int i, va_list ap)
{
	int sum = 0;

	switch (format[i + 1])
	{
		case 'c':
			return (print_char(va_arg(ap, int)));
		case 's':
			return (print_string(va_arg(ap, char*)));
		case '%':
			return (print_char('%'));
		case 'd':
		case 'i':
			print_int(va_arg(ap, int), &sum);
			return (sum);
		case 'b':
			print_binary(va_arg(ap, long), BASE_BINA, &sum);
			return (sum);
        case 'o':
            print_binary(va_arg(ap, long), BASE_OCTA, &sum);
            return (sum);
        case 'x':
            print_binary(va_arg(ap, long), BASE_HEXA_S, &sum);
            return (sum);
        case 'X':
            print_binary(va_arg(ap, long), BASE_HEXA_C, &sum);
            return (sum);
        case 'u':
            print_unsigned(va_arg(ap, unsigned int), &sum);
            return (sum);
		default:
			print_char('%');
			print_char(format[i + 1]);
			return (2);
	}
}

/**
 * _printf - printf
 *
 * @format: format
 *
 * Return: number of char printed
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	int i = 0;
	va_list ap;

	if (!format)
		return (-1);

	va_start(ap, format);

	while (format[i])
	{
		if (format[i] != '%')
		{
			print_char(format[i]);
			counter++;
			i++;
		}
		else
		{
			if (!format[i + 1] || format[i + 1] == ' ')
				return (-1);
			counter += do_print(format, i, ap);
			i += 2;
		}
	}
	return (counter);
}
