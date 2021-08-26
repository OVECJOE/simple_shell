#include "shell.h"

/**
 * main - The User Interface
 * @argc: Unused
 * @argv: an array of command line arguments passed to the command name
 *
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	int (*builtin)(char **, int);
	char **tokens;
	char *line;
	size_t len = 0;
	ssize_t nread;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			init_prompt();

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			return (1);

		if (*line == '\n' || *line == '\0')
			continue;

		rm_newline(line);
		tokens = parse_input(line);

		builtin = check_builtins(tokens);
		if (builtin)
		{
			builtin(tokens, status);
			free_memory_pp(tokens);
			continue;
		}
		status = execute(tokens, argv[0]);

		free_memory_pp(tokens);
	}

	return (0);
}
