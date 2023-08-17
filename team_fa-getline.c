#include "team_fa_lib.h"

/**
* teamfa_getline -This is a user-defined getline function.
*
* @lineptr: string parameter1
* @n: string parameter2
* @stream: string parameter3
*
* Return: Always count (success).
*/
ssize_t teamfa_getline(char **lineptr, size_t *n, FILE *stream)
{
size_t count = 0;
char c;
while ((c = (char)getc(stream)) != '\n' && count < *n - 1)
{
(*lineptr)[count++] = c;
}
(*lineptr)[count] = '\0';
return (count);
}

/**
* main -Entry point.
*
* @void: void parameter
* Return: Always 0 (success).
*/
int main(void)
{
char *team_fa_line = NULL;
/* Initialize n to a value */
size_t n = 10;

while (1)
{
ssize_t count = teamfa_getline(&team_fa_line, &n, stdin);
_printf("%s and its length: %ld characters.\n", team_fa_line, count);

/* clean up memory after each iteration */
free(team_fa_line);
team_fa_line = NULL;
/* reset n for the next iteration */
n = 10;
}
return (0);
}

