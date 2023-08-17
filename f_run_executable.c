#include "team_fa_lib.h"

/**
* run_executable -This function help to run executable.
*
* @tokens: string parameter
* Return: Always void (success).
*/

void run_executable(char **tokens)
{
if (execvp(tokens[0], tokens) == -1)
{
perror("No such file or directory");
exit(EXIT_FAILURE);
}
}
