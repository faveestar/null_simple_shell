#include "team_fa_lib.h"

/**
* tokenize_input -This function help to split token.
*
* @input: string parameter1
* @tokens: string parameter2
* Return: Always void (success).
*/

void tokenize_input(char *input, char **tokens)
{
int idx = 0;
char *token = strtok(input, " \t\n");
while (token != NULL)
{
tokens[idx++] = strdup(token);
token = strtok(NULL, " \t\n");
}
tokens[idx] = NULL;
}
