#include "simpleshell.h"

/**
 * handle_signal - prints new line and prompt when CTRL + C is passed as input
 * @signal: name of sig
 */
void handle_signal(int signal)
{
	(void) signal;
	write(1, "\033[0;36m\n{^_^} ", 15);
	write(1, "\033[0m ", 4);
	fflush(stdout);
}

/**
 * _stat - displays file or file system status
 * @str: pointer to what is being checked
 * Return: 0 on success or -1 on failure
 */
int _stat(char *str)
{
	struct stat var;

	if (stat(str, &var) == 0)
		return (0);
	return (-1);
}

