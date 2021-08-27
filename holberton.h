#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>

#define PATH_MAX 1024
extern char **environ;

int main(int argc, char *argv[]);

/*used in _strings.c file*/
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strlen(const char *s);

/*used in envset_unset.c*/
int shell_environ(void);
int _setenv(char *var_name, char *var_value);
char *var_build(char *var_name, char *var_value);
int _unsetenv(char *var_name);

/*used in cd_handler.c file*/
char *_getcwd(void);
int cd_home(void);
int cd_prev(void);
int _cd(char **args);

/*used in ctrl_exit.c file*/
void print_prompt(void);
char *ignore_space(char *str);
void ctrl_c(int signum);
void shell_exit(char **args, char *line);

/*used in execute.c file*/
unsigned int _occurence(char *s);
char **_strtotokens(char *str);
int check_file_status(char *filename);
int _execute(char **tokens, char *line, char *args);

/*used in read_line.c file*/
char *read_line2(void);
void free_args(char **args);
char *read_line(void);

/*used in _realloc.c file*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/*used in builtin_parser.c file*/
int builtin_parser(char **tokens);

/*used in path_handler.c file*/
int get_path(char **args);
char *get_env(char *path);
char *cmd_build(char *token, char *dir_value);

/*used in print_char.c file*/
int _putchar(char c);
void _print(char *str);

int shell_help(char **args);
/*history*/
int get_history(char *input);
int display_history(void);
#endif /*HOLBERTON_H*/
