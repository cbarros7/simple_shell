#include "simpleshell.h"

/**
 * read_input - stores whatever is passed to it as standard input
 * Return: string containing the input
 */
char *read_input(void)
{
	char *line = NULL;
	ssize_t signal;
	size_t bufsize = 0;
	int i;

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
char **sparse_str(char *line, char **env)
{
	int bufsize = TOK_BUFSIZE, posicion = 0;
	char **tokens = _calloc(sizeof(char *), bufsize);
	char *token;

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
		token = strtok(NULL, TOK_DELIM);
	}
	if (tokens[0] == NULL)
		tokens[posicion] = "\n"; //si es nulo esa pos es un new line

	/*COMPARA EL TOKENS[0]*/
	if ((_strcmp(tokens[0], "exit") == 0) && tokens[1] == NULL)
	{
		free(line); /*LIBERA MEMORIA Y SALE DEL PROGRAMA*/
		free(tokens);
		exit(0);
	}
	if ((_strcmp(tokens[0], "env") == 0) && tokens[1] == NULL)
		func_printenv(env);      /*Encuentra el enviroment*/

	return (tokens);
}


/**
 * prompt - prints '$' and waits for a user's input
 */
void prompt(void)
{
	char *buffer = getcwd(NULL, 0); /*directorio actual - recibe input*/
	if (isatty(STDIN_FILENO))
		/*verifica si el STDIN refiere la terminal*/
	{
		write(1, "\033[0;36m{^_^} ", 13);
		write(1, "\033[0m ", 4);
	}
	free(buffer); /*LIBERA MEMORIA*/
}
