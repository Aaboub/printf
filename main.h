#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

#define BASE_BINA 2
#define BASE_OCTA 8
#define BASE_HEXA_S 16
#define BASE_HEXA_C 17


int _printf(const char *format, ...);
int print_char(char c);
int print_string(const char *s);
void print_int(int i, int *sum);
void print_base(long i, int base, int *sum);
void print_unsigned(unsigned int i, int *sum);

#endif
