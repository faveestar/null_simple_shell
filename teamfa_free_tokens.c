#include "team_fa_lib.h"

/**
* free_tokens -This function help free tokens.
*
* @tokens: string parameter
* Return: Always void (success).
*/

void free_tokens(char **tokens)
{
int idx;
for (idx = 0; tokens[idx] != NULL; idx++)
{
free(tokens[idx]);
}
}
