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
            i++;
		}
		else
		{
			if (!format[i + 1] || format[i + 1] == ' ')
			{
				return (-1);
			}
			switch(format[i + 1])
			{
				case 'c':
                    counter += _putchar(va_arg(ap, int));
                    break;
                case 's':
                    counter += print_string(va_arg(ap, char*));
                    break;
                case '%':
                    counter += _putchar('%');
                    break;
                default:
                    counter += _putchar('%');
                    counter += _putchar(format[i + 1]);
			}
            i += 2;
		}
	}

	return (counter);
}
