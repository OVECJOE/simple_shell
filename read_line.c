#include "holberton.h"
/**
 *free_args - frees a two dimensional string
 *@args:array of pointers to strings
 *Return:void
 */
void free_args(char **args)
{
	int i = 0;

	for (i = 0; args[i]; i++)
	{
		free(args[i]);
	}
	free(args);
}
/**
 *read_line - reads user's input from stdin
 *
 *Return:pointer to string containing user input
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	int var = 0;

	var = getline(&line, &len, stdin);
	if (var == EOF)
	{
		free(line);
		exit(0);
	}
	if (line == NULL)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(-1);
	}

	return (line);
}
