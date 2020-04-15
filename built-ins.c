#include "simpleshell.h"

/**
 * func_printenv - prints the current environment
 * @environ: environment variable
 */
void func_printenv(char **environ)
{
	int i = 0;

	for (; environ[i] ; i++)
		_puts(environ[i]); /*imprime todo el environment*/
}
