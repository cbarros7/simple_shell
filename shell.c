#include "SimpleShell.h"

int main(void)
{
	char *line;
	char **args;
	int status;

	signal(SIGINT, handle_signal);
	do {
		printf("$ ");
		/*read input and return string*/
		line = read_input();
		/*separates string to get command and atgs*/
		args = sparse_str(line);
		/*executes ars*/
		status = execute(args);
		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}
