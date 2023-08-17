#include "team_fa_lib.h"

/**
* execute_command -This function help to execute command.
*
* @input_tokens: string parameter
*
* Return: Always void (success).
*/
void execute_command(char **input_tokens)
{
pid_t child_pid;
int status;

child_pid = fork();
if (child_pid == -1)
{
perror("fork");
return;
}
else if (child_pid == 0)
{
/* Child process */
execvp(input_tokens[0], input_tokens);
perror("execvp");
exit(EXIT_FAILURE);
}
else
{
/* Parent process */
waitpid(child_pid, &status, 0);
}
}
