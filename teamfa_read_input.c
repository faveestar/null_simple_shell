#include "teamfa_shell.h"
/**
* teamfa_read_line - This function read line from stdin.
*
* @void: parameter
* Return: character on success
*/
char *teamfa_read_line(void)
{
char *__line = NULL;
size_t __bufsize = 0;
ssize_t __chars_read;

__chars_read = getline(&__line, &__bufsize, stdin);

if (__chars_read == -1)
{
perror("input error");
exit(1);
}

return (__line);
}
