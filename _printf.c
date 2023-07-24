#include "main.h"

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

/**
 * _putchar - Writes a character to the standard output (stdout)
 * @c: The character to be written
 * Return: On success, returns the character written. On error, -1 is returned.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * _printf - Custom Printf function
 * @format: format string.
 * Return: Number of characters printed (excluding the null byte used to end output to strings).
 */
int _printf(const char *format, ...)
{
    if (format == NULL)
        return -1;

    char buffer[BUFF_SIZE];
    int buff_ind = 0;
    int printed_chars = 0;

    for (; *format; format++)
    {
        if (*format != '%')
        {
            buffer[buff_ind++] = *format;
            if (buff_ind == BUFF_SIZE)
                print_buffer(buffer, &buff_ind);
            else
                printed_chars++;
        }
        else
        {
            format++; // Move past the '%'
            switch (*format)
            {
                case 'c':
                {
                    char c = (char)__builtin_va_arg(&format, int);
                    buffer[buff_ind++] = c;
                    if (buff_ind == BUFF_SIZE)
                        print_buffer(buffer, &buff_ind);
                    else
                        printed_chars++;
                    break;
                }

                case 's':
                {
                    char *str = __builtin_va_arg(&format, char *);
                    if (str != NULL)
                    {
                        int i = 0;
                        while (str[i])
                        {
                            buffer[buff_ind++] = str[i];
                            if (buff_ind == BUFF_SIZE)
                                print_buffer(buffer, &buff_ind);
                            else
                                printed_chars++;
                            i++;
                        }
                    }
                    break;
                }

                case '%':
                {
                    buffer[buff_ind++] = '%';
                    if (buff_ind == BUFF_SIZE)
                        print_buffer(buffer, &buff_ind);
                    else
                        printed_chars++;
                    break;
                }

                default:
                    buffer[buff_ind++] = *format;
                    if (buff_ind == BUFF_SIZE)
                        print_buffer(buffer, &buff_ind);
                    else
                        printed_chars++;
            }
        }
    }

    print_buffer(buffer, &buff_ind);

    return printed_chars;
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add the next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
    if (*buff_ind > 0)
    {
        int i;
        for (i = 0; i < *buff_ind; i++)
            _putchar(buffer[i]);

        *buff_ind = 0;
    }
}

