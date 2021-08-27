#include "shell.h"

/**
 * rm_newline - Removes the new line from User's input
 * @line: the line inputted by user
 *
 * Return: input without newline
 */
char *rm_newline(char *line)
{
	char *temp = line;

	temp = strtok(temp, "\n");
	return (temp);
}

/**
 * parse_input - parses the line entered by the user
 * @line: the given input
 *
 * Return: an array of tokens present in @line
 */
char **parse_input(char *line)
{
	char **tokens;
	char *tok, *temp;
	int i;

	if (!line)
		return (NULL);

	tokens = malloc(sizeof(char *) * _strlen(line));
	if (!tokens)
	{
		perror("Gsh");
		return (NULL);
	}

	line = rm_newline(line);

	temp = _strdup(line);
	tok = strtok(temp, " ");
	for (i = 0; tok; i++)
	{
		tokens[i] = _strdup(tok);
		tok = strtok(NULL, " ");
	}
	tokens[i] = NULL;

	free(temp);

	return (tokens);
}

/**
 * build_path - build the path to a command
 * @token: the given command
 * @value: the path to build for @token
 *
 * Return: @value/@token - the path of command
 */
char *build_path(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (!cmd)
		return (NULL);
	memset(cmd, 0, len);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}

/**
 * check_cmd_path - check if command is in path
 * @cmd: an array of command strings
 *
 * Return: 0 if found, else 1
 */
int check_cmd_path(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv("PATH");
	value = strtok(path, ":");
	while (value)
	{
		cmd_path = build_path(*cmd, value);

		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup(cmd_path);
			free(cmd_path);
			return (0);
		}
		free(cmd_path);
		value = strtok(NULL, ":");
	}

	return (1);
}

