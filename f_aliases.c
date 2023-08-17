#include "team_fa_lib.h"

/**
* teamfa_print_aliases -This function print aliases.
*
* @void: void parameter
*
* Return: Always void (success).
*/

void teamfa_print_aliases(void)
{
Alias aliases[MAXIMUM_ARGUMENTS];
int alias_count = 0;
int idx1;

for (idx1 = 0; idx1 < alias_count; idx1++)
{
_printf("%s='%s'\n", aliases[idx1]._name, aliases[idx1]._value);
}
}

/**
* teamfa_print_specified_aliases -This function print specific aliases.
*
* @alias_names: string parameter
* @count: integer parameter
*
* Return: Always void (success).
*/
void teamfa_print_specified_aliases(char **alias_names, int count)
{
int idx1, idx2;
int alias_count = 0;
Alias aliases[MAXIMUM_ARGUMENTS];

for (idx1 = 0; idx1 < count; idx1++)
{
for (idx2 = 0; idx2 < alias_count; idx2++)
{
if (_strcmp(alias_names[idx1], aliases[idx2]._name) == 0)
{
_printf("%s='%s'\n", aliases[idx2]._name, aliases[idx2]._value);
break;
}
}
}
}


/**
* teamfa_define_aliases -This function define aliases.
*
* @alias_definitions: string parameter
* @count: integer parameter
*
* Return: Always void (success).
*/
void teamfa_define_aliases(char **alias_definitions, int count)
{
int idx1, idx2, alias_count = 0;
Alias aliases[MAXIMUM_ARGUMENTS];

for (idx1 = 0; idx1 < count; idx1++)
{
char *_name = strtok(alias_definitions[idx1], "=");
char *_value = strtok(NULL, "=");

int _alias_index = -1;

for (idx2 = 0; idx2 < alias_count; idx2++)
{
if (_strcmp(_name, aliases[idx2]._name) == 0)
{
_alias_index = idx2;
break;
}
}

if (_alias_index != -1)
{
/* Update existing alias */
free(aliases[_alias_index]._value);
aliases[_alias_index]._value = strdup(_value);
}
else
{
/* Define new alias */
aliases[alias_count]._name = strdup(_name);
aliases[alias_count]._value = strdup(_value);
alias_count++;
}
}
}

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
if (argCount == 1)
{
/* Print all aliases */
teamfa_print_aliases();
}
else
{
if (argCount == 2)
{
/* Print specified aliases */
char *alias_names[MAXIMUM_ARGUMENTS];
tokenize_input(argVector[1], alias_names);
teamfa_print_specified_aliases(alias_names, argCount - 1);
}
else
{
/* Define/update aliases */
int idx1;
char *alias_definitions[MAXIMUM_ARGUMENTS];

for (idx1 = 1; idx1 < argCount; idx1++)
{
alias_definitions[idx1 - 1] = argVector[idx1];
}

teamfa_define_aliases(alias_definitions, argCount - 1);
}
}

return (0);
}
