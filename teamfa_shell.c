#include "teamfa_shell.h"

/**
* main -The program Entry point.
*
* Return: Always 0 (success).
*/

int main(void)
{
while (1)
{
char *command = read_input();
run_command(command);
free(command);
}

return (0);
}

