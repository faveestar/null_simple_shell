#include "team_fa_lib.h"

/**
* teamfa_setenv -This is a user-defined setenv function.
*
* @name: string parameter1
* @value: string parameter2
* @overwrite: integer parameter3
*
* Return: Always integer (success).
*/

/* function to implement the setenv command */
int teamfa_setenv(const char *name, const char *value, int overwrite)
{
char *env_entry;

if (name == NULL || name[0] == '\0')
{
perror("setenv");
return (-1);
}

if (!overwrite && getenv(name) != NULL)
{
/* don't overwrite existing variable if not allowed */
return (0);
}

env_entry = malloc(_strlen(name) + strlen(value) + 2);
if (env_entry == NULL)
{
perror("setenv");
return (-1);
}

sprintf(env_entry, "%s=%s", name, value);

if (putenv(env_entry) != 0)
{
perror("setenv");
free(env_entry);
return (-1);
}

return (0);
}


/**
* teamfa_unsetenv -This is a user-defined unsetenv function.
*
* @name: string parameter
*
* Return: Always integer (success).
*/
/* function to implement the unsetenv command */
int teamfa_unsetenv(const char *name)
{
if (name == NULL || name[0] == '\0')
{
perror("unsetenv");
return (-1);
}

if (unsetenv(name) != 0)
{
perror("unsetenv");
return (-1);
}

return (0);
}

/**
* main -Entry point
*
* @void: void parameter
*
* Return: Always 0 (success).
*/
int main(void)
{
/* Example usage of setenv */
if (teamfa_setenv("MY_VARIABLE", "my_value", 1) == 0)
{
_printf("Setenv successful\n");
}

/* Example usage of unsetenv */
if (teamfa_unsetenv("MY_VARIABLE") == 0)
{
_printf("Unsetenv successful\n");
}

return (0);
}

