#include "team_fa_lib.h"
#include <unistd.h>

/**
* put_character - writes the character c to stdout
* @c: The character to print
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
* Description: put_character uses a local buffer of 1024 to call write
* as little as possible
*/
int put_character(char c)
{
static char buffer[1024];
static int idx;

if (c == -1 || idx >= 1024)
{
ssize_t bytes_written = write(1, &buffer, idx);
if (bytes_written < 0)
{
perror("write");
/* Handle the error appropriately, e.g., return an error code.*/
}
idx = 0;
}
if (c != -1)
{
buffer[idx] = c;
idx++;
}
return (1);
}

/**
* put_string - prints a string to stdout
* @str: pointer to the string to print
* Return: number of chars written
*/
int put_string(char *str)
{
register int i;

for (i = 0; str[i] != '\0'; i++)
put_character(str[i]);
return (i);
}

/**
* print_percentage - prints a percent
* @list: va_list arguments from _printf
* @flags: pointer to the struct flagContainer in which we turn the flags on
* Return: number of char printed
*/
int print_percentage(va_list list, flagContainer_t *flags)
{
(void)list;
(void)flags;
return (put_character('%'));
}

/**
* print_str - loops through a string and prints
* every character
* @list: va_list arguments from _printf
* @flags: pointer to the struct flagContainer that determines
* if a flag is passed to _printf
* Return: number of char printed
*/
int print_str(va_list list, flagContainer_t *flags)
{
char *s = va_arg(list, char *);

(void)flags;

if (!s)
s = "(null)";
return (put_string(s));
}

/**
* convert_num - converts number and base into string
* @num: input number
* @base: input base
* @lowercase: flag if hexa values need to be lowercase
* Return: result string
*/
char *convert_num(unsigned long int num, int base, int lowercase)
{
static char *represent;
static char buffer[50];
char *ptr;

represent = (lowercase)
? "0123456789abcdef"
: "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';
do {
*--ptr = represent[num % base];
num /= base;
} while (num != 0);

return (ptr);
}

