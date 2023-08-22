#include "main.h"

/**
 * _printf - printf
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
			_putchar(format[i]);
			counter++;
		}
		else
		{
			if (!format[i + 1] || (format[i + 1] == ' ' && (!format[i + 2] || format[i + 2] == ' ')))
			{
				return (-1);
			}
			else if (format[i + 1] == ' ')
			{
				_putchar(format[i + 1]);
				counter++;
				i += 2;
			}
			switch(format[i + 1])
			{
				case 'c':
					_putchar(va_arg(ap, int));
                    counter++;
                    i+= 2;
                    break;
                case 's':
                    counter += print_string(va_arg(ap, char*));
                    i+= 2;
                    break;
			}
		}
		i++;
	}

	return (counter);
}
