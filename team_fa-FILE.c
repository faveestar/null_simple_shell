#include "team_fa_lib.h"

/**
* run_shell_from_file -This function run shell from a file
*
* @filename: string parameter
*
* Return: Always 0 (success).
*/

void run_shell_from_file(const char *filename)
{
FILE *_file;
char _line[MAX_INPUT_LENGTH];
char *_command_tokens[MAXIMUM_ARGUMENTS];

_file = fopen(filename, "r");
if (_file == NULL)
{
perror("Error opening file");
exit(1);
}

while (fgets(_line, sizeof(_line), _file))
{
/* Remove newline character from the end of the line */
size_t length = strlen(_line);
if (length > 0 && _line[length - 1] == '\n')
{
_line[length - 1] = '\0';
}

/* Tokenize the input line into command tokens */
tokenize_input(_line, _command_tokens);

/* Execute the command */
execute_command(_command_tokens);
}

fclose(_file);
}
