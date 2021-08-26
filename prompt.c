#include "shell.h"

/**
 * init_prompt - initialize prompt
 *
 * Return: void
 */
void init_prompt(void)
{
	int p_l, s_l, t_l;
	char *p, *s, *t = "> ";
	char *prompt = NULL;

	p = _getenv("USER");
	s = _getenv("NAME");

	p_l = _strlen(p);
	s_l = _strlen(s);
	t_l = _strlen(t);

	prompt = malloc(p_l + s_l + t_l + 1);
	if (!p || !s || !prompt)
	{
		print("$ ");
		return;
	}

	prompt = _strcpy(prompt, p);
	prompt = _strcat(prompt, "@");
	prompt = _strcat(prompt, s);
	prompt = _strcat(prompt, t);

	print(prompt);

	free(prompt);
}

