#include "teamfa_shell.h"

/**
* read_input -The function read input from stdin.
*
* @void: parameter
* Return: Always character array (success).
*/

char *read_input(void)
{
char *line = NULL;
size_t len = 0;
ssize_t read;

printf(PROMPT);
fflush(stdout); /* Ensure prompt is displayed */

read = getline(&line, &len, stdin);

if (read == -1)
{
if (feof(stdin))
{
/* Handle end of file (Ctrl+D) */
free(line);
exit(0);
}
else
{
perror("getline");
free(line);
exit(1);
}
}

/* Remove the trailing newline character */
line[strcspn(line, "\n")] = '\0';

return (line);
}

/**
* execute_command -The function execute the command given.
*
* @_command: parameter
* Return: Always 0 (success).
*/
void execute_command(char *_command)
{
pid_t pid;
int status;

pid = fork();

if (pid == 0)
{
/* Child process */
if (access(_command, X_OK) == 0)
{
if (execlp(_command, _command, NULL) == -1)
{
/* Exec failed, print an error message */
perror("exec");
exit(1);
}
}
else
{
/* Command not found, print error */
ssize_t _result = write(STDERR_FILENO, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
if (_result == -1)
{
perror("write");
}
_exit(1);
}
}
else if (pid > 0)
{
/* Parent process */
waitpid(pid, &status, 0);
}
else
{
/* Fork failed */
perror("fork");
exit(1);
}
}
