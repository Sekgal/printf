
#define MAIN_H
#ifndef MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#define BUFF_SIZE 1024

int _printf(const char *format, ...);
void print_buffer(char buffer[], int *buff_ind);
int _putchar(char c);
void print_buffer(char buffer[], int *buff_ind);
int _itoa(int num, char *buffer, int buff_size);


#endif
