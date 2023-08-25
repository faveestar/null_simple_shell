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
