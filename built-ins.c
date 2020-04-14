#include "simpleshell.h"

/**
 * func_exit - exits the shell
 * @args: the command being passed to exit
 * Return: 0
 */
int func_exit(char **args)
{
	(void) args;
	exit(0);
}

/**
 * func_printenv - prints the current environment
 * @args: the command being passed to print the environment
 * Return: 1
 */
int func_printenv(char **args)
{
	char **array = environ;
	int i;
	(void) args;

	for (i = 0; array[i]; i++)
	{
		printf("%s\n", array[i]);
	}

	return (1);
}

