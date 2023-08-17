#include "team_fa_lib.h"

/**
* print_character - prints a character
* @list: va_list arguments from _printf
* @flags: pointer to the struct flagContainer that determines
* if a flag is passed to _printf
* Return: number of char printed
*/
int print_character(va_list list, flagContainer_t *flags)
{
(void)flags;
put_character(va_arg(list, int));
return (1);
}

/**
* print_integer - prints an integer
* @list: va_list of arguments from _printf
* @flags: pointer to the struct flagContainer determining
* if a flag is passed to _printf
* Return: number of char printed
*/
int print_integer(va_list list, flagContainer_t *flags)
{
int n = va_arg(list, int);
int res = count_digit(n);

if (flags->gap == 1 && flags->addition == 0 && n >= 0)
res += put_character(' ');
if (flags->addition == 1 && n >= 0)
res += put_character('+');
if (n <= 0)
res++;
print_number(n);
return (res);
}

/**
* print_memory_address - prints address of input in hexadecimal format
* @list: va_list arguments from _printf
* @flags: pointer to the struct flagContainer that determines
* if a flag is passed to _printf
* Return: number of char printed
*/
int print_memory_address(va_list list, flagContainer_t *flags)
{
char *convertedStr;
unsigned long int addr = va_arg(list, unsigned long int);

register int count = 0;

(void)flags;

if (!addr)
return (put_string("(nil)"));
convertedStr = convert_num(addr, 16, 1);
count += put_string("0x");
count += put_string(convertedStr);
return (count);
}

/**
* print_number - helper function that loops through
* an integer and prints all its digits
* @n: integer to be printed
*/
void print_number(int n)
{
unsigned int n1;

if (n < 0)
{
put_character('-');
n1 = -n;
}
else
n1 = n;

if (n1 / 10)
print_number(n1 / 10);
put_character((n1 % 10) + '0');
}

/**
* count_digit - returns the number of digits in an integer
* for _printf
* @i: integer to evaluate
* Return: number of digits
*/
int count_digit(int i)
{
unsigned int d = 0;
unsigned int u;

if (i < 0)
u = i * -1;
else
u = i;
while (u != 0)
{
u /= 10;
d++;
}
return (d);
}
