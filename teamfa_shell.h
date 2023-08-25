#ifndef TEAMFA_SHELL_H
#define TEAMFA_SHELL_H

/* include headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>


#define PROMPT "teamfa$> "
#define ERROR_MESSAGE "No such file or directory\n"

char *read_input(void);
void execute_command(char *_command);
void run_command(char* _command);

#endif /* TEAMFA_SHELL_H */

