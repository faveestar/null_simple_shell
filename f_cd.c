#include "team_fa_lib.h"

/**
* _printError -This function print error message.
*
* @_message: string parameter
* Return: Always void (success).
*/
void _printError(const char *_message)
{
_printf("cd: %s\n", _message);
}

/**
* _updateEnvironmentVariables -This function update env variables.
*
* @_currentDir: string parameter1
* @_oldPwd: string parameter2
*
* Return: Always void (success).
*/
void _updateEnvironmentVariables(char *_currentDir, char *_oldPwd)
{
if (_currentDir != NULL)
{
setenv("PWD", _currentDir, 1);
free(_currentDir);
}

if (_oldPwd != NULL)
{
setenv("OLDPWD", _oldPwd, 1);
free(_oldPwd);
}
}
/**
* _changeDirectory -This function change directory.
*
* @_targetDir: string parameter1
* @_oldPwd: string parameter2
*
* Return: Always integer (success).
*/
int _changeDirectory(const char *_targetDir, char **_oldPwd)
{
*_oldPwd = getcwd(NULL, 0);
if (*_oldPwd == NULL)
{
_printError(strerror(errno));
return (1);
}

if (chdir(_targetDir) != 0)
{
_printError(strerror(errno));
free(*_oldPwd);
return (1);
}

return (0);
}
/**
* main -Entry point.
*
* @argCount: argument count parameter1
* @argVector: argument vector parameter2
* Return: Always 0 (success).
*/
int main(int argCount, char *argVector[])
{
char *_home_dir = getenv("HOME"), *_old_pwd = NULL, *_current_dir;
if (_home_dir == NULL)
{
_printError("HOME environment variable not set");
return (1);
}
if (argCount == 1 || (argCount == 2 && _strcmp(argVector[1], "~") == 0))
{
if (_changeDirectory(_home_dir, &_old_pwd) != 0)
return (1);
}
else if (argCount == 2 && _strcmp(argVector[1], "-") == 0)
{
char *_previous_dir = getenv("OLDPWD");
if (_previous_dir == NULL)
{
_printError("OLDPWD not set");
return (1);
}
if (_changeDirectory(_previous_dir, &_old_pwd) != 0)
{
return (1);
}
}
else
{
if (_changeDirectory(argVector[1], &_old_pwd) != 0)
{
return (1);
}
}
_current_dir = getcwd(NULL, 0);
if (_current_dir == NULL)
{
_printError(strerror(errno));
return (1);
}
_updateEnvironmentVariables(_current_dir, _old_pwd);
return (0);
}
