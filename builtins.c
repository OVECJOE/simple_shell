#include "shell.h"

/**
 * is_builtin - checks if a command is a builtin command
 * @cmd: the given command
 *
 * Return: the position of @cmd in the builtins array, else -1
 */
builtin_t is_builtin(char *cmd)
{
	builtin_t builtins[] = {
		{"exit", exit_cmd},
		{"env", env_cmd},
		{NULL, NULL}
	};

	int i;

	for (i = 0; builtins[i].cmd; i++)
		if (_strcmp(builtins[i].cmd, cmd) == 0)
			return (builtins[i]);

	return (builtins[i]);
}

/**
 * check_builtins - If command is a builtin command
 * @cmd: an array of command and its arguments
 *
 * Return: the appropriate function to be executed, else NULL
 */
int (*check_builtins(char **cmd))(char **, int, char *)
{
	builtin_t b = is_builtin(cmd[0]);

	if (b.cmd)
		return (b.f);

	return (NULL);
}

/**
 * env_cmd - builtin implementation of env command
 * @cmd: Unused
 * @status: the status code
 *
 * Return: Always 0
 */
int env_cmd(char **cmd, int status, char *filename)
{
	int i;

	(void) cmd;
	(void) status;
	(void) filename;

	for (i = 0; environ[i]; i++)
	{
		print(environ[i]);
		_putchar('\n');
	}
	return (0);
}

/**
 * exit_cmd - builtin Implementation of exit command
 * @cmd: an array of given command and its arguments
 * @status: the status code
 *
 * Return: exit with the status code given by user, or
 * previous execution status code
 */
int exit_cmd(char **cmd, int status, char *filename)
{
	int i = 0;

	if (!cmd[1])
	{
		free_memory_pp(cmd);
		exit(status);
	}

	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i]) && cmd[1][i] != '-')
		{
			print(filename);
			print(": ");
			print(cmd[0]);
			print(": ");
			print("Illegal number: ");
			print(cmd[1]);
			_putchar('\n');
			return (1);
		}

		i++;
	}

	status = _atoi(cmd[1]);
	free_memory_pp(cmd);

	exit(status);
}

