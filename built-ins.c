#include "simpleshell.h"

/**
 * func_printenv - prints the current environment
 * @args: the command being passed to print the environment
 * Return: 1
 */
void func_printenv(char **environ)
{
	int i = 0;

	for (; environ[i] ; i++)
		_puts(environ[i]); /*imprime todo el environment*/
}
