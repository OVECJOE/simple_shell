#include "holberton.h"

/**
 *print_prompt - displays promot b4 user inputs
 *
 *Return:void
 */
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		_print("#cisfun$ ");
	}
}
/**
 *ctrl_c - suppresses quitting when Ctrl c is invoked
 *@signum:SIGINT variable
 *Return:void
 */
void ctrl_c(int signum)
{
	(void)signum;
	signal(SIGINT, ctrl_c);
	write(STDIN_FILENO, "\n#cisfun$ ", 11);
}
/**
 *shell_exit - exits a shell,taking into account different exit statuses
 *@args:arguements passed
 *@line:string to free
 *Return:void
 */
void shell_exit(char **args, char *line)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
		if (status >= 0)
		{
			free(line);
			free(args);
			exit(status);
		}
		printf("Exit: illegal status: %s\n", args[1]);
	}
	else
	{
		free(line);
		free(args);
		exit(0);
	}
}
