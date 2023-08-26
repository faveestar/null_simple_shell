#include "teamfa_shell.h"
/**
* main - Entry point
*
* @void: parameter
* Return: integer
*/

int main(void)
{
int __response;
char *__input_line;
char **__tokens;
int __is_interactive = isatty(fileno(stdin));
int idx;

do {
if (__is_interactive)
{
printf("$teamfa#: ");
fflush(stdout);
}
__input_line = teamfa_read_line();
/* Remove the trailing newline. */
__input_line[strlen(__input_line) - 1] = '\0';
__tokens = teamfa_tokenize_string(__input_line);
__response = teamfa_execute_command(__tokens);

free(__input_line);
for (idx = 0; __tokens[idx] != NULL; idx++)
{
free(__tokens[idx]);
}
free(__tokens);
} while (__is_interactive && __response != -1);

return (0);
}

