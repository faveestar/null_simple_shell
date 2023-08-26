#include "teamfa_shell.h"
/**
* _strcmp -This function compares two strings
* @s1: parameter1
* @s2: parameter2
* Return: cmpValue
*/


int _strcmp(char *s1, char *s2)
{
int count, cmpValue;

count = 0;
while (s1[count] == s2[count] && s1[count] != '\0')
{
count++;
}

cmpValue = s1[count] - s2[count];
return (cmpValue);
}
