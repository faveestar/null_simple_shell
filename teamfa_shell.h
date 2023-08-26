#ifndef TEAMFA_SHELL_H
#define TEAMFA_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

/* function prototypes */
int teamfa_execute_command(char **cmd);
char *teamfa_read_line(void);
char **teamfa_tokenize_string(char *str);
int _strcmp(char *s1, char *s2);




#endif /* TEAMFA_SHELL_H */

