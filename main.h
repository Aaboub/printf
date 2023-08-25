#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(const char *s);
void print_int(int i, int *sum);
void print_binary(int i, int *sum);

#endif
