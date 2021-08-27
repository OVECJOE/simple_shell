#ifndef SHELL_H
#define SHELL_H

/* Header Files */
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* Macros */
#define TRUE 1
#define FALSE 0
#define BUFSIZE 1024

/* Global Variables */
extern char **environ;

/**
 * struct builtin_t - Structure for builtin commands
 * @cmd: the command's name
 * @f: the appropriate function to act on command
 */
typedef struct builtin_t
{
	char *cmd;
	int (*f)(char **, int, char *);
} builtin_t;

/*----------//My Function Prototypes\\----------*/
/*==============================================*/

/* In executor.c */
int execute(char **cmd, char *filename);

/* In prompt.c */
void init_prompt(void);

/* In parser.c */
char *rm_newline(char *line);
char **parse_input(char *line);
char *build_path(char *token, char *value);
int check_cmd_path(char **cmd);

/* In string.c */
int _strlen(const char *s);
char *_strstr(char *haystack, char *needle);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);

/* In getenv.c */
char *_getenv(const char *name);

/* In printers.c */
int _putchar(int c);
int print(char *str);

/* In utils.c */
void free_memory_p(char *);
void free_memory_pp(char **);
int cmp(const char *s1, const char *s2);
int _atoi(char *s);
int _isalpha(char c);

/* In more_string.c */
char *_strdup(char *s);

/* In builtins.c */
int exit_cmd(char **, int, char *);
int env_cmd(char **, int, char *);
builtin_t is_builtin(char *cmd);
int (*check_builtins(char **))(char **, int, char *);

#endif
