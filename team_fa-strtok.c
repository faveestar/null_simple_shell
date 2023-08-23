#include "team_fa_lib.h"

/**
* teamfa_strtok -This is a user-defined strtok function.
*
* @string: string parameter1
* @delimeter: string parameter2
* @saveptr: string parameter3
*
* Return: Always tokens (success).
*/

char *teamfa_strtok(char *string, const char *delimeter, char **saveptr)
{
char *_token_start;
char *_token_end;

if (string != NULL)
{
*saveptr = string;
}

if (*saveptr == NULL || **saveptr == '\0')
{
return (NULL);
}

_token_start = *saveptr;
_token_end = strpbrk(*saveptr, delimeter);

if (_token_end == NULL)
{
*saveptr = NULL;
return (_token_start);
}

*_token_end = '\0';
*saveptr = _token_end + 1;

return (_token_start);
}

/**
* helper_strtok -This function help strtok.
*
* @void: void parameter
* Return: Always 0 (success).
*/
int helper_strtok(void)
{
char input[] = "Team,Favour,&,Azeez,on,this";
char *saveptr;

char *token = teamfa_strtok(input, ",", &saveptr);
while (token != NULL)
{
_printf("Token: %s\n", token);
token = teamfa_strtok(NULL, ",", &saveptr);
}

return (0);
}

