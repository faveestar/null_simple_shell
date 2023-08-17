#include "team_fa_lib.h"

/**
* display_binary - prints a number in base 2
* @list: va_list arguments from _printf
* @flags: pointer to the struct flagContainer that determines
* if a flag is passed to _printf
* Description: the function calls convert() which in turns converts the input
* number into the correct base and returns it as a string
* Return: the number of char printed
*/
int display_binary(va_list list, flagContainer_t *flags)
{
unsigned int num = va_arg(list, unsigned int);
char *str = convert_num(num, 2, 0);

(void)flags;
return (put_string(str));
}

/**
* display_hex - prints a number in hexadecimal base,
* in lowercase
* @list: va_list arguments from _printf
* @flags: pointer to the struct flagContainer that determines
* if a flag is passed to _printf
* Description: the function calls convert() which in turns converts the input
* number into the correct base and returns it as a string
* Return: the number of char printed
*/
int display_hex(va_list list, flagContainer_t *flags)
{
unsigned int num = va_arg(list, unsigned int);
char *str = convert_num(num, 16, 1);
int count = 0;

if (flags->hashKey == 1 && str[0] != '0')
count += put_string("0x");
count += put_string(str);
return (count);
}

/**
* display_hex_big - prints a number in hexadecimal base,
* in uppercase
* @list: va_list arguments from _printf
* @flags: pointer to the struct flagContainer that determines
* if a flag is passed to _printf
* Description: the function calls convert() which in turns converts the input
* number into the correct base and returns it as a string
* Return: the number of char printed
*/
int display_hex_big(va_list list, flagContainer_t *flags)
{
unsigned int num = va_arg(list, unsigned int);
char *str = convert_num(num, 16, 0);
int count = 0;

if (flags->hashKey == 1 && str[0] != '0')
count += put_string("0X");
count += put_string(str);
return (count);
}

/**
* display_octal - prints a number in base 8
* @list: va_list arguments from _printf
* @flags: pointer to the struct flagContainer that determines
* if a flag is passed to _printf
* Description: the function calls convert_num() which in turns convert
* the input number into the correct base and returns it as a string
* Return: the number of char printed
*/
int display_octal(va_list list, flagContainer_t *flags)
{
unsigned int num = va_arg(list, unsigned int);
char *str = convert_num(num, 8, 0);
int count = 0;

if (flags->hashKey == 1 && str[0] != '0')
count += put_character('0');
count += put_string(str);
return (count);
}

/**
* display_rot13_string - prints a string using rot13
* @list: list of arguments from _printf
* @flags: pointer to the struct flagContainer that determines
* if a flag is passed to _printf
* Return: length of the printed string
*/
int display_rot13_string(va_list list, flagContainer_t *flags)
{
int i, j;
char rot13[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ROT13[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
char *s = va_arg(list, char *);

(void)flags;
for (j = 0; s[j]; j++)
{
if (s[j] < 'A' || (s[j] > 'Z' && s[j] < 'a') || s[j] > 'z')
put_character(s[j]);
else
{
for (i = 0; i <= 52; i++)
{
if (s[j] == rot13[i])
put_character(ROT13[i]);
}
}
}

return (j);
}
