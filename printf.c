#include "main.h"

/**
 * print_arg - do actual printing
 *
 * @arg: param
 * @ap: param
 * @buffer: param
 * @pos: param
 *
 * Return: number of printed chars
 */
int print_arg(const char arg, va_list ap, char *buffer, int *pos)
{
	int i;

	operation operations[] = {{'c', print_char}, {'s', print_string},
		{'%', print_percent}, {'d', print_int}, {'i', print_int},
		{'b', print_base}, {'o', print_base}, {'x', print_base},
		{'X', print_base}, {'u', print_nsign}, {'S', print_string}};

	for (i = 0; i < 11; i++)
	{
		if (arg == operations[i].op)
			return (operations[i].function(ap, arg, buffer, pos));
	}
	return (-1);
}

/**
 * is_valid_arg - is valid
 * @arg: param
 *
 * Return: int
 */
int is_valid_arg(char arg)
{
	return (arg != '\0' && (arg != 'c' && arg != 's'
				&& arg != 'd' && arg != 'i' && arg != 'b'
				&& arg != 'o' && arg != 'x' && arg != 'X'
				&& arg != 'u' && arg != '%' && arg != 'S'));
}

/**
 * _printf - printf
 * @format: format
 *
 * Return: number of char printed
 */
int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int counter = 0;
	int pos = 0;
	int i = 0;
	va_list ap;

	if (!format)
		return (-1);

	va_start(ap, format);

	while (format[i])
	{
		if (format[i] != '%' || is_valid_arg(format[i + 1]))
		{
			counter += write_buffer(buffer, &pos);
			buffer[pos] = format[i];
			pos++;
			i++;
		}
		else
		{
			if (!format[i + 1] || format[i + 1] == ' ')
			{
				write_buffer_force(buffer, &pos);
				va_end(ap);
				return (-1);
			}
			counter += print_arg(format[i + 1], ap, buffer, &pos);
			i += 2;
		}
	}
	counter += write_buffer_force(buffer, &pos);
	va_end(ap);
	return (counter);
}
