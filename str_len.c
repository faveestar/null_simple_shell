#include "team_fa_lib.h"
/**
* _strlen -This functure returns the length of a string
* @s: pointer parameter
* Return: Always (integer)
*/

int _strlen(const char *s)
{
int len = 0;
while (*s != '\0')
{
len++;
s++;
}
return (len);
/* This return an integer value */
}
