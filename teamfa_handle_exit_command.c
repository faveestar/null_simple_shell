/**
* handle_exit_command -This function help handle exit.
*
* @input_tokens: string parameter
* Return: Always void (success).
*/
void handle_exit_command(char **input_tokens)
{
if (_strcmp(input_tokens[0], "exit") == 0)
{
process_exit_command();
}
}

