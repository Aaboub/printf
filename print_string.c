#include "main.h"

/**
 * do_print_string - do print
 * @s: param
 */
int do_print_string(char *s){
    int i = 0;

    if (s)
    {
        while (*s)
        {
            put_char(*s);
            s++;
            i++;
        }
        return (i);
    }
    return (do_print_string("(null)"));
}

/**
 * print_string - Entry
 * @s: param
 */
int print_string(va_list ap, int arg)
{
    char *s = va_arg(ap, char*);

    return do_print_string(s);
}
