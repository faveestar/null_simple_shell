#include "teamfa_shell.h"
/**
* run_command -The function run CLI arguments.
*
* @_command: parameter
* Return: Always character array (success).
*/
void run_command(char *_command)
{
pid_t pid;
int status;
pid = fork();

if (pid == 0)
{
char *args[256] = { NULL }; /* Array to store command and arguments */
int num_args = 0;          /* Count of arguments */

char *token = strtok(_command, " ");
while (token != NULL && num_args < 255)
{
args[num_args++] = token;
token = strtok(NULL, " ");
}

if (num_args > 0)
{
if (execvp(args[0], args) == -1)
perror("exec");
_exit(1);
}
else
_exit(0);
}
else if (pid > 0)
waitpid(pid, &status, 0);
else
perror("fork");
exit(1);
}
