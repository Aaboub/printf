#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

#define BASE_IGNO -1
#define BASE_BINA 2
#define BASE_OCTA 8
#define BASE_HEXA_S 16
#define BASE_HEXA_C 17

#define UNUSED(x) (void)(x)


int _printf(const char *format, ...);
int put_char(char c);
int print_char(va_list ap, int arg);
int print_string(va_list ap, int arg);
int print_int(va_list ap, int arg);
int print_base(va_list ap, int arg);
int print_nsigned(va_list ap, int arg);

#endif
