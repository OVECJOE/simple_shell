#include "holberton.h"

/**
 * _occurence - return the number of occurence of a string
 * @s: string to check
 * Return: integer
 */
unsigned int _occurence(char *s)
{
	int i, cnt = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		/*test for all delimeters*/
		if (s[i]  == ' ' || s[i] == '\t' || s[i] == '\n')
			cnt++;
	}

	return (cnt);
}
/**
 *_strtotokens - split a sentence into multiple words.
 *@str: the string passed as argument.
 *Return: tokens
 */
char **_strtotokens(char *str)
{
	int i = 0;
	const char separator[] = " \t\n";
	int spaces = _occurence(str);
	char **tokens = malloc(sizeof(char *) * (spaces + 1));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "sh: allocation error\n");
		exit(1);
	}

	token = strtok(str, separator);

	while (token != NULL)
	{
		tokens[i] = token;
		token = strtok(NULL, separator);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 *check_file_status - checks whether a file exists
 *@filename:name of file
 *Return:0 - file is available, -1 otherwise
 */
int check_file_status(char *filename)
{
	struct stat st;

	if (stat(filename, &st) == -1)
		return (-1);
	return (0);
}
/**
 *_execute - executes a file given as input
 *@tokens:split tokens from stdin input
 *@line:line from stdin to free
 *Return:-1 (success), -1,otherwise
 */
int _execute(char **tokens, char *line, char *args)
{
	char *err1, *err2, *err3;
	pid_t cpid;
	int status;
	struct stat st;

	/*handle when token is a builtin cmd or NULL*/
	if (builtin_parser(tokens) == 0 || *tokens == NULL)
	{
		return (1);
	}
	/*fork the process*/
	cpid = fork();
	if (cpid < 0)
	{
		perror("Error:fork->-1");
		return (EXIT_FAILURE);
	}
/*child process*/
	if (cpid == 0)
	{
		if (stat(*tokens, &st) != 0)
		{
			get_path(tokens);
		}
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			err1 = strcat(*tokens, ": No such file or directory\n");
			err2 = strcat(args, ":");
			err3 = strcat(err2, err1);
			write(STDERR_FILENO, err3, _strlen(err3));
			/*free(err1);*/
			/*free(err2);*/
			/*free(err3);*/
			free(line);
			free(tokens);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
wait(&status);
return (1);
}
