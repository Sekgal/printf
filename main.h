
#define MAIN_H
#ifndef MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#define BUFF_SIZE 1024

int _putchar(char ch);
int _puts(char *string);
int printc(char *format, va_list);
int printstr(char *format, va_list);
int (*driver(char *format))(char *format, va_list);
int _printf(char *format, ...);
int printint(char *format, va_list pa);
int integer(int number);
int contadordigit(int number);
int _abs(int number);
int printpercent(char *format, va_list pa);
int printhex(char *format, va_list);
int printHEX(char *format, va_list);
int printocta(char *format, va_list);
int print_unsign(char *format, va_list);

#endif
