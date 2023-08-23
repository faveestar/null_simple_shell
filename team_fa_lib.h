#ifndef TEAM_FA_H
#define TEAM_FA_H



/* simple shell project header content */

/**
* struct _Person - Represents a person's information.
* @_name: The name of the person.
* @_month: The present month in ALX SE
*/
struct _Person
{
char *_name;
int _month;
};


/**
* struct Alias - Represents Aliases.
* @_name: The name of Alias.
* @_value: The value of Alias
*/
typedef struct
{
char *_name;
char *_value;
} Alias;



/* list of include header used */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* list of macro used */
#define MAX_INPUT_LENGTH 1024
#define MAXIMUM_ARGUMENTS 100

/* list of function prototypes */

void tokenize_input(char *input, char **tokens);
void run_executable(char **tokens);
void process_exit_command();
void process_user_input();
void free_tokens(char **tokens);
void handle_exit_command(char **input_tokens);
void execute_command(char **input_tokens);
void process_user_input();
ssize_t teamfa_getline(char **lineptr, size_t *n, FILE *stream);
char *teamfa_strtok(char *string, const char *delimeter, char **saveptr);
int teamfa_setenv(const char *name, const char *value, int overwrite);
int teamfa_unsetenv(const char *name);
void _printError(const char *_message);
void _updateEnvironmentVariables(char *_currentDir, char *_oldPwd);
int _changeDirectory(const char *_targetDir, char **_oldPwd);

void run_shell_from_file(const char *filename);

void teamfa_print_aliases();
void teamfa_print_specified_aliases(char **alias_names, int count);
void teamfa_define_aliases(char **alias_definitions, int count);


/* list of helper functions */
int helper_aliases(int argCount, char *argVector[]);
int helper_cd(int argCount, char *argVector[]);
int helper_strtok(void);
int helper_setenv(void);
int helper_getline(void);
/* end of simple shell header content */





#include <stdlib.h>
#include <stdarg.h>

/**
* struct flagContainer - struct containing flags to "activate"
* when a flag specifier is passed to custom_printf()
* @addition: flag for the '+' character
* @gap: flag for the ' ' character
* @hashKey: flag for the '#' character
*/
typedef struct flagContainer
{
int addition;
int gap;
int hashKey;
} flagContainer_t;

/**
* struct formatHandler - struct to select the appropriate function
* based on the format specifier passed to custom_printf()
* @specifier: format specifier
* @handler: pointer to the right printing function
*/
typedef struct formatHandler
{
char specifier;
int (*handler)(va_list ap, flagContainer_t *flags);
} formatHandler_t;


/* List of other prototypes */
int _putchar(char c);
int _islower(int c);
int _isalpha(int c);
int _abs(int n);
int _isupper(int c);
int _isdigit(int c);
int _strlen(const char *s);
void _puts(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
char *_memset(char *s, char b, unsigned int n);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_strchr(char *s, char c);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
char *_strstr(char *haystack, char *needle);



/* numericPrinter */
int print_integer(va_list list, flagContainer_t *flags);
void print_number(int num);
int display_unsigned(va_list list, flagContainer_t *flags);
int count_digit(int integer);

/* basePrinter */
int display_hex(va_list list, flagContainer_t *flags);
int display_hex_big(va_list list, flagContainer_t *flags);
int display_binary(va_list list, flagContainer_t *flags);
int display_octal(va_list list, flagContainer_t *flags);

/* converterFunc */
char *convert_num(unsigned long int num, int base, int lower);

/* _printf */
int _printf(const char *format, ...);

/* obtain_printer */
int (*obtain_printer(char s))(va_list, flagContainer_t *);

/* fetch_flag */
int fetch_flag(char s, flagContainer_t *flags);

/* alphabeticPrinter */
int print_str(va_list list, flagContainer_t *flags);
int print_character(va_list list, flagContainer_t *flags);

/* writeHelper */
int put_character(char c);
int put_string(char *str);

/* customPrints */
int display_rot13_string(va_list list, flagContainer_t *flags);
int display_reversed_string(va_list list, flagContainer_t *flags);
int display_uppercase_S(va_list list, flagContainer_t *flags);

/* print_address */
int print_memory_address(va_list list, flagContainer_t *flags);

/* print_percent */
int print_percentage(va_list list, flagContainer_t *flags);

#endif /* TEAM_FA_H */
