#include "SimpleShell.h"

/**
 * main - creates a prompt that reads input, sparses it, executes and waits
 * for another command unless told to exit
 * Return: EXIT_SUCCESS
 */
int main(void)
{
	char *line;
	char **args;
	int status;

	signal(SIGINT, handle_signal);
	do {
		/*printf("$ ");*/
		prompt();

		/*read input and return string*/
		line = read_input();
		/*separates string to get command and atgs*/
		args = sparse_str(line);
		/*executes args*/
		status = execute(args);
		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}
