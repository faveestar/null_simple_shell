#include "team_fa_lib.h"

/**
* obtain_printer - selects the right printing function
* based on the conversion specifier passed to _printf
* @s: character that holds the conversion specifier
* Description: the function loops through the structs array
* handler_arr[] to find a match between the specifier passed to _printf
* and the first element of the struct, and then selects the appropriate
* printing function
* Return: a pointer to the matching printing function
*/
int (*obtain_printer(char s))(va_list, flagContainer_t *)
{
formatHandler_t handler_arr[] = {
{'i', print_integer},
{'s', print_str},
{'c', print_character},
{'d', print_integer},
{'u', display_unsigned},
{'x', display_hex},
{'X', display_hex_big},
{'b', display_binary},
{'o', display_octal},
{'R', display_rot13_string},
{'r', display_reversed_string},
{'S', display_uppercase_S},
{'p', print_memory_address},
{'%', print_percentage},
{'\0', NULL}
};
int totalFlags = sizeof(handler_arr) / sizeof(formatHandler_t) - 1;

register int index;

for (index = 0; index < totalFlags; index++)
if (handler_arr[index].specifier == s)
return (handler_arr[index].handler);
return (NULL);
}

/**
* display_reversed_string - prints a string in reverse
* @list: argument from _printf
* @flags: pointer to the struct flagContainer that determines
* if a flag is passed to _printf
* Return: length of the printed string
*/
int display_reversed_string(va_list list, flagContainer_t *flags)
{
int i = 0, j;
char *s = va_arg(list, char *);

(void)flags;
if (!s)
s = "(null)";

while (s[i])
i++;

for (j = i - 1; j >= 0; j--)
put_character(s[j]);

return (i);
}

/**
* display_unsigned - prints an unsigned integer
* @list: va_list of arguments from _printf
* @flags: pointer to the struct flagContainer determining
* if a flag is passed to _printf
* Return: number of char printed
*/
int display_unsigned(va_list list, flagContainer_t *flags)
{
unsigned int u = va_arg(list, unsigned int);
char *str = convert_num(u, 10, 0);

(void)flags;
return (put_string(str));
}

/**
* display_uppercase_S - Non printable characters
* (0 < ASCII value < 32 or >= 127) are
* printed this way: \x, followed by the ASCII code
* value in hexadecimal (upper case - always 2 characters)
* @list: va_list arguments from _printf
* @flags: pointer to the struct flagContainer that determines
* if a flag is passed to _printf
* Return: number of char printed
*/
int display_uppercase_S(va_list list, flagContainer_t *flags)
{
int i, count = 0;
char *convertedResult;
char *s = va_arg(list, char *);

(void)flags;
if (!s)
return (put_string("(null)"));

for (i = 0; s[i]; i++)
{
if (s[i] > 0 && (s[i] < 32 || s[i] >= 127))
{
put_string("\\x");
count += 2;
convertedResult = convert_num(s[i], 16, 0);
if (!convertedResult[1])
count += put_character('0');
count += put_string(convertedResult);
}
else
count += put_character(s[i]);
}
return (count);
}

/**
* fetch_flag - activates flags if _printf identifies
* a flag modifier in the format string
* @s: character that holds the flag specifier
* @flags: pointer to the struct flagContainer in which we activate the flags
*
* Return: 1 if a flag has been activated, 0 otherwise
*/
int fetch_flag(char s, flagContainer_t *flags)
{
int flagSwitched = 0;

switch (s)
{
case '+':
flags->addition = 1;
flagSwitched = 1;
break;
case ' ':
flags->gap = 1;
flagSwitched = 1;
break;
case '#':
flags->hashKey = 1;
flagSwitched = 1;
break;
}

return (flagSwitched);
}
