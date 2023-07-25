
#define MAIN_H
#ifndef MAIN_H

#include <unistd.h>

#include <stdarg.h>

#define BUFF_SIZE 1024

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int _putchar(char c);
int _itoa(int num, char *buffer, int buff_size);


#endif /* MAIN_H */
