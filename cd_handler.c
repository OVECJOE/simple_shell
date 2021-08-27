#include "holberton.h"
/**
 *_getcwd - gets the current working directory
 *Return:string containing current working directory
 */
char *_getcwd(void)
{
	size_t len = PATH_MAX;
	char *cwd;

	cwd = malloc(sizeof(char) * len);
	if (cwd == NULL)
	{
		perror("Error: Memory allocation cwd\n");
		return (NULL);
	}
	if (getcwd(cwd, len) == NULL)
	{
		free(cwd);
		perror("Error: getcwd->NULL\n");
		return (NULL);
	}
	return (cwd);
}
/**
 *cd_home - handles cd when the user does not set any other arguements
 *Return:0 on success
 */
int cd_home(void)
{
	char *cwd, *home;

/*get the current working directory then set OLDPWD to its value*/
	cwd = _getcwd();
	_setenv("OLDPWD", cwd);
	free(cwd);
/*get the value of Home variable then change cwd to it*/
	home = get_env("HOME");
	chdir("home");
	free(home);
/*set the cwd to the changed dir*/
	cwd = _getcwd();
	_setenv("PWD", cwd);
	free(cwd);

	return (0);
}
/**
 *cd_prev - navigates to the previous directory when user invokes cd -
 *Return:0 - success
 */
int cd_prev(void)
{
	char *prev, *cwd;

/*get cwd then set OLDPWD to its value*/
	cwd = _getcwd();

	prev = getenv("OLDPWD");
	chdir(prev);
	prev = NULL;

	_setenv("OLDPWD", cwd);
	cwd = NULL;

	cwd = _getcwd();
	_setenv("PWD", cwd);
	free(cwd);

	return (0);
}
/**
 *_cd - changes the current working dir
 *@args:parsed cmds from readline
 *Return:0
 */
int _cd(char **args)
{
	char *cwd;

	if (args[1] != NULL)
	{
/*handle cd prev*/
		if (strncmp(args[1], "-", 1) == 0)
		{
			cd_prev();
		}
		else
		{
			cwd = _getcwd();
			_setenv("OLDPWD", cwd);
			free(cwd);

			if (chdir(args[1]) == -1)
			{
				perror("Error: chdir\n");
			}
			cwd = _getcwd();
			_setenv("PWD", cwd);
			free(cwd);
		}
	}
	else
	{
		cd_home();
	}
	return (0);
}
