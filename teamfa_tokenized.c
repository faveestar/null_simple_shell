#include "teamfa_shell.h"
/**
* teamfa_tokenize_string - This function read token.
*
* @str: parameter
* Return: tokens array
*/
char **teamfa_tokenize_string(char *str)
{
char **__tokens = NULL;
char *__token;
int __token_count = 0;

/* Space, tab, and newline are delimiters. */
const char __delimiters[] = " \t\n";

__token = strtok(str, __delimiters);
while (__token != NULL)
{
__tokens = realloc(__tokens, (__token_count + 1) * sizeof(char *));
if (__tokens == NULL)
{
perror("Memory allocation error");
exit(1);
}
__tokens[__token_count] = strdup(__token);
__token_count++;
__token = strtok(NULL, __delimiters);
}

__tokens = realloc(__tokens, (__token_count + 1) * sizeof(char *));
if (__tokens == NULL)
{
perror("Memory allocation error");
exit(1);
}
__tokens[__token_count] = NULL;

return (__tokens);
}

