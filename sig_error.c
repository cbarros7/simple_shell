#include "simpleshell.h"

/**
 * _access - Check if a filename have permissions
 * @filename: Filename to check
 * Return: On success 1, On error -1, if file not found -10
 **/
int _access(char *filename)
{
	struct stat stats;

	if (stat(filename, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
			return (1);
		else
			return (-1);
	}

	return (-10);
}

/**
 * handle_signal - prints new line and prompt when CTRL + C is passed as input
 * @signal: name of sig
 */
void handle_signal(int signal)
{
	(void) signal;
	write(1, "\n{^_^} ", 7);
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

/**
 * _error - prints the error output of a file
 * @argv: name of program
 * @count: number of prompt
 * @args: command to be put in
 * @access: permission of file
 * Return: 0 on success
 */
int *_error(char *argv, int count, char *args, int access)
{
	char *number;

	number = _itoa(count, 10);
	if (access == -10 || access == 1)
	{
		write(2, argv, _strlen(argv));
		write(2, ": ", 2);
		write(2, number, _strlen(number));
		write(2, ": ", 2);
		write(2, args, _strlen(args));
		write(2, ": not found\n", 12);
	}
	else if (access == -1)
	{
		write(2, argv, _strlen(argv));
		write(2, ": ", 2);
		write(2, number, _strlen(number));
		write(2, ": ", 2);
		write(2, args, _strlen(args));
		write(2, ": Permission denied\n", 20);
	}

	return (0);
}
