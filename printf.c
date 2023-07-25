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
 * _itoa - Converts an integer to a string
 * @num: The integer to convert
 * @buffer: The buffer to store the converted string
 * @buff_size: The size of the buffer
 * @base: The numeric base (e.g., 2 for binary)
 * Return: The length of the converted string
 */
int _itoa(unsigned int num, char *buffer, int buff_size, int base)
{
    if (base < 2 || base > 36)
        return 0;

    int i = buff_size - 1;
    buffer[i--] = '\0';

    if (num == 0)
    {
        buffer[i--] = '0';
        return i + 1;
    }

    while (num > 0 && i >= 0)
    {
        int rem = num % base;
        if (rem < 10)
            buffer[i--] = rem + '0';
        else
            buffer[i--] = rem - 10 + 'a';

        num /= base;
    }

    return i + 1;
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

    va_list args;
    va_start(args, format);

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
                case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    int len = _itoa((unsigned int)num, &buffer[buff_ind], BUFF_SIZE - buff_ind, 10);
                    if (len > 0)
                    {
                        buff_ind += len;
                        if (buff_ind == BUFF_SIZE)
                            print_buffer(buffer, &buff_ind);
                        else
                            printed_chars += len;
                    }
                    break;
                }

                case 'b':
                {
                    unsigned int num = va_arg(args, unsigned int);
                    int len = _itoa(num, &buffer[buff_ind], BUFF_SIZE - buff_ind, 2);
                    if (len > 0)
                    {
                        buff_ind += len;
                        if (buff_ind == BUFF_SIZE)
                            print_buffer(buffer, &buff_ind);
                        else
                            printed_chars += len;
                    }
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

    va_end(args);

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

