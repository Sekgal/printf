#include"main.h"
#define BUFF_SIZE 1024

void print_buffer(char buffer[],int*buff_ind);
/**
 * _putchar - Writes a character to the standard output (stdout)
 *@c: The character to be written
 * Return: On success, returns the character written. On error, -1 is returned.
 */
int _putchar(char c)
{
	return write (1,&c,1);
}
/**
 *_itoa- converts an integer to a string
 *@num:The integer to convert
 *@buffer:The buffer to store the converted string
 *@buff_size:The size of the buffer
 *Return:The length of the converted string
 */
int _itoa(int num,char *buffer ,int buff_size)
{
	int i=buff_size-1;
	buffer[i--]='\0';
	if(num==0)
	{
		buffer[i--]='0';
		return i+1;
	}
	int is_negative=0;
	if(num<0)
	{
		is_negative=1;
		num=-num;
	}
	while (num>0&&i>=0)
	{
		buffer[i--]=(num%10)+'0';
		num/=10;
	}
	if(is_negative && i>=0)
		buffer[i--]='_';
	return i+1;
}
/**
 *_printf-custom printf function
 *@format:format string.
 *Return:number of characters printed (excluding the null bytes used to end output to strings).
 */
int _print(const char *format, ...)
{
	if(format == NULL)
		return -1;

