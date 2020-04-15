#include "simpleshell.h"

/**
 * main - creates a prompt that reads input, sparses it, executes and waits
 * for another command unless told to exit
 * @ac: number of arguemnets
 * @av: array of arguements
 * @environ: environment variable
 * Return: EXIT_SUCCESS
 */
int main(int ac __attribute__((unused)),  __attribute__((unused)) char **av, char **environ)
{
	char *line;
	char **args, **path;
	int status = 0;
	signal(SIGINT, handle_signal);
	while (1) {
		prompt();
		/*read input and return string*/
		line = read_input();
		/*separates string to get command and atgs*/
		args = sparse_str(line, environ);

		if ((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env") != 0))    /*compara que el comando no sea igual un nulo o a la palabra env*/
		{
			path = search_path(environ); /*buscar la palabra PATH en la variable environ*/
			status = _stat(args, path);
			child_process(args, environ, status);
		}
		else
		{
			free(args);
		}
		free (line);
	}
	return (EXIT_SUCCESS);
}
