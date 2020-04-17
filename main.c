#include "simpleshell.h"

/**
 * main - creates a prompt that reads input, sparses it, executes and waits
 * for another command unless told to exit
 * @ac: number of arguemnets
 * @av: array of arguements
 * @env: environment variable
 * Return: EXIT_SUCCESS
 */
int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *line;
	char **args, **path;
	int count = 0, status = 0;
	(void) av;
	signal(SIGINT, handle_signal);
	while (1)
	{
		prompt();
		/*read input and return string*/
		line = read_input();
		/*separates string to get command and atgs*/
		args = sparse_str(line, env);

		if ((_strcmp(args[0], "\n") != 0) && (_strcmp(args[0], "env") != 0))
		{
			count += 1;
			path = search_path(env); /*busca PATH en la variable environ*/
			status = _stat(args, path);
			child_process(av, args, env, status, count);
		}
		else
		{
			free(args);
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}
