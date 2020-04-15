#include "simpleshell.h"

/**
 * func_exit - exits the shell
 * @args: the command being passed to exit
 * Return: 0
 */
int func_exit(char **args)
{
	(void) args;
	free(args);
	exit(-1);
}

/**
 * func_printenv - prints the current environment
 * @args: the command being passed to print the environment
 * Return: 1
 */
int func_printenv(char **args)
{
	int i;
	char **env;
	(void) args;

	env = environ;

	for (i = 0; env[i]; i++)
	{
		write(1, env[i], _strlen(env[i]));
	}

	return (1);
}
