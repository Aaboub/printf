#include "main.h"

/**
 * write_buffer - check if full and write buffer
 * @buffer: param
 * @pos: param
 *
 * Return: int
 */
int write_buffer(char *buffer, int *pos)
{
    int i;

    if (*pos == BUFFER_SIZE)
    {
        for (i = 0; i < BUFFER_SIZE; i++)
            put_char(buffer[i]);
        (*pos) = 0;
        return BUFFER_SIZE;
    }
    return 0;
}

/**
 * write_buffer_force - empty what's left in buffer before exiting
 * @buffer: param
 * @pos: param
 *
 * Return: int
 */
int write_buffer_force(char *buffer, const int *pos)
{
    int i;

    for (i = 0; i < *pos; i++)
            put_char(buffer[i]);
    return *pos;
}

/**
 * put_char - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1 else -1
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}
