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
if (access(_command, X_OK) == 0)
{
if (execlp(_command, _command, NULL) == -1)
{
perror("exec");
exit(1);
}
}
else
{
ssize_t _result = write(STDERR_FILENO, ERROR_MESSAGE, strlen(ERROR_MESSAGE));
if (_result == -1)
{
perror("write");
}
_exit(1);
}
}
else if (pid > 0)
waitpid(pid, &status, 0);
else
{
perror("fork");
exit(1);
}
}
