#include "team_fa_lib.h"

/**
* _printf - produces output according to a format
* @format: format string containing the characters and the specifiers
* Description: this function will call the obtain_printer() function that will
* determine which printing function to call depending on the conversion
* specifiers contained into format string
* Return: length of the formatted output string
*/
int _printf(const char *format, ...)
{
int (*pfunc)(va_list, flagContainer_t *);
const char *p;
va_list arguments;
flagContainer_t flags = {0, 0, 0};

register int count = 0;

va_start(arguments, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = format; *p; p++)
{
if (*p == '%')
{
p++;
if (*p == '%')
{
count += put_character('%');
continue;
}
while (fetch_flag(*p, &flags))
p++;
pfunc = obtain_printer(*p);
count += (pfunc)
? pfunc(arguments, &flags)
: _printf("%%%c", *p);
}
else
count += put_character(*p);
}
put_character(-1);
va_end(arguments);
return (count);
}
