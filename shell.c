#include "SimpleShell.h"

/**
 * main - creates a prompt that reads input, sparses it, executes and waits
 * for another command unless told to exit
 * @argc: number of arguemnets
 * @argv: array of arguements
 * Return: EXIT_SUCCESS
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *line;
	char **args;
	int status, count = 0;

	signal(SIGINT, handle_signal);
	do {
		/*printf("$ ");*/
		prompt();

		/*read input and return string*/
		line = read_input();
		/*separates string to get command and atgs*/
		args = sparse_str(line);
		/*executes args*/
		count += 1;
		status = execute(args, argv, count);
		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}
