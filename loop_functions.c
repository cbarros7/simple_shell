#include "SimpleShell.h"

/**
 * read_input - stores whatever is passed to it as standard input
 * Return: string containing the input
 */
char *read_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	int i;
	ssize_t signal;

	signal = getline(&line, &bufsize, stdin);
	if (!line)
	{
		perror("Error allocating memory for buffer");
		return (0);
	}
	if (signal == -1)
	{
		free(line);
		return (NULL);
	}
	else if (signal == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line);
		exit(0);
	}
	else
	{
		for (i = 0; line[i] == ' ' && line[i + 1] == ' '; i++)
			;
		if (!line[i] && line[i + 1] == '\n')
		{
			free(line);
			return (0);
		}
	}
	return (line);
}

/**
 * sparse_str - devides a string into and array of strings
 * @line: the string to be separated
 * Return: tokens(array of strings) on succes or EXIT_FAILURE if fails
 */
char **sparse_str(char *line)
{
	int bufsize = TOK_BUFSIZE, posicion = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;

	if (!tokens)
	{
		printf("error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[posicion] = token;
		posicion++;
		if (posicion >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens_backup = tokens;
			tokens = _realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				free(tokens_backup);
				printf("error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[posicion] = NULL;
	return (tokens);
}

/**
 * execute - executes a command that is passed to it as the first aguement
 * @args: command being passed to be executed
 * @argv: external input arguemnets
 * @count: command prompt counter
 * Return: a pointer to a function if builtin or a forked process that
 * executes a function in a path specified
 */
int execute(char **args, char **argv, int count)
{
	char *array_commands[] = {
		"exit",
		"env"
	};

	int (*array_functions[]) (char **) = {
		&func_exit,
		&func_printenv,
	};
	int i = 0;
	int size = sizeof(array_commands) / sizeof(char *);

	if (args[0] == NULL)
		return (1);
	while (i < size)
	{
		if (strcmp(args[0], array_commands[i]) == 0)
		{
			return ((*array_functions[i])(args));
		}
		i++;
	}
	return (child_process(args, argv, count));
}

/**
 * prompt - prints '$' and waits for a user's input
 */
void prompt(void)
{
	char *buffer = getcwd(NULL, 0); /*directorio actiual - recibe input*/
	char *token = strtok(buffer, "/");

	while (token != NULL)
		token = strtok(NULL, "/");

	if (isatty(fileno(stdin)))
		/*verifica si el STDIN refiere la terminal*/
	{
		write(1, "\033[0;36m{^_^} ", 13);
		write(1, "\033[0m ", 4);
	}

	free(buffer); /*LIBERA MEMORIA*/
}
