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
int do_print(const char i, va_list ap, char* buffer)
{
	switch (i)
	{
		case 'c':
			return (print_char(ap, BASE_IGNO));
		case 's':
			return (print_string(ap, BASE_IGNO));
		case 'd':
		case 'i':
			return (print_int(ap, BASE_IGNO));
		case 'b':
            return (print_base(ap, BASE_BINA));
        case 'o':
            return (print_base(ap, BASE_OCTA));
        case 'x':
            return (print_base(ap, BASE_HEXA_S));
        case 'X':
            return (print_base(ap, BASE_HEXA_C));
        case 'u':
            return(print_unsigned(ap, BASE_IGNO));
        case '%':
            return (put_char('%'));
		default:
			put_char('%');
			put_char(i);
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

    char buffer[1024];

	while (format[i])
	{
		if (format[i] != '%')
		{
            buffer[i] = format[i];
			counter++;
			i++;
		}
		else
		{
			if (!format[i + 1] || format[i + 1] == ' ')
				return (-1);
			counter += do_print(format[i + 1], ap, buffer);
			i += 2;
		}
	}
	return (counter);
}
