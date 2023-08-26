#include "teamfa_shell.h"
/**
* teamfa_execute_command - This function execute command.
*
* @cmd: parameter
* Return: integer
*/
int teamfa_execute_command(char **cmd)
{
pid_t __child_pid;
int __status;

if (_strcmp("exit", cmd[0]) == 0)
return (-1);

__child_pid = fork();

if (__child_pid == -1)
{
perror("Fork error");
return (1);
}
else if (__child_pid == 0)
{
if (execvp(cmd[0], cmd) == -1)
{
perror("Command execution error");
exit(1);
}
}
else
{
waitpid(__child_pid, &__status, 0);
}

return (0);
}
