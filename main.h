#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

#define BASE_BINA 'b'
#define BASE_OCTA 'o'
#define BASE_HEXA_S 'x'
#define BASE_HEXA_C 'X'

#define BUFFER_SIZE 1024U

#define UNUSED(x) (void)(x)

typedef struct operation
{
    char op;
    int (*function)(va_list, char, char*,int*);
} operation;

int _printf(const char *format, ...);
int put_char(char c);
int print_char(va_list ap, char arg, char *buffer, int *pos);
int print_string(va_list ap, char arg, char *buffer, int *pos);
int print_percent(va_list ap, char arg, char *buffer, int *pos);
int print_int(va_list ap, char arg, char *buffer, int *pos);
int print_base(va_list ap, char arg, char *buffer, int *pos);
int print_nsign(va_list ap, char arg, char *buffer, int *pos);
int write_buffer(char *buffer, int *pos);
int write_buffer_force(char *buffer, const int *pos);

#endif
