#include "SimpleShell.h"

char *read_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t signal;

	signal = getline(&line, &bufsize, stdin);
	if (!line)
	{
		perror("Error allocating memory for buffer");
		return (0);
	}
	if (signal == 1)
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

	return (line);
}

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
			tokens = realloc(tokens, bufsize * sizeof(char *));
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

int execute(char **args)
{
	char *array_commands[] = {
		/*"help",*/
		"exit",
		"env"
	};

	int (*array_functions[]) (char **) = {
		/*&func_help,*/
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
	return (child_process(args));
}
