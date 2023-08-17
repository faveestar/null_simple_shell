#include "team_fa_lib.h"

/**
* main -Entry point.
*
* @argCount: integer parameter
* @argVector: string parameter
*
* Return: Always 0 (success).
*/
int main(int argCount, char *argVector[])
{
FILE *_file;
char _line[MAX_INPUT_LENGTH];
char *_command_tokens[MAXIMUM_ARGUMENTS];

if (argCount != 2)
{
_printf("Usage: %s [filename]\n", argVector[0]);
return (1);
}

_file = fopen(argVector[1], "r");
if (_file == NULL)
{
perror("Error opening file");
return (1);
}

while (fgets(_line, sizeof(_line), _file))
{
/* Remove newline character from the end of the line */
size_t length = _strlen(_line);
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
return (0);
}

