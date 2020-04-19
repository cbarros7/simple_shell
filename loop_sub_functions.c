#include "simpleshell.h"

/**
 * _which - identifies the path of the command(*args) that is being passed
 * to it
 * @foundpath: the command that is being passed to it
 * Return: the complete path of the command or 0 on failure
 */
char **_which(char *foundpath)
{
	int size = TOK_BUFSIZE, i = 0;
	char *copy_path = NULL, *tokens = NULL, *sparse = ":=";
	char **dir = _calloc(sizeof(char *), size);

	if (foundpath == NULL)
	{
		free(foundpath);
		return (0);
	}
	if (dir == NULL)
	{
		free(foundpath);
		perror("Error allocated memory");
		return (NULL);
	}

	copy_path = _strdup(foundpath); /*copiar el string --> palabra PATH*/
	tokens = strtok(copy_path, sparse); /*separar el string por un separador*/
	while (tokens != NULL)
	{
		dir[i] = tokens;
		i++;
		tokens = strtok(NULL, sparse);
	}

	return (dir);
}


/**
 * child_process - executes a command if the path of it is an executable file
 * @args: the command to be executed
 * @env: environment variable
 * @status_main: status variable
 * @av: name of program
 * @cnt: count of prompt
 * Return: 1
 */
int child_process(char **av, char **args, char **env, int status_main, int cnt)
{
	pid_t pid;
	int status;

	if (args == NULL)
		return (-1);

	pid = fork();
	if (pid  < 0)
	{
		perror("./hsh: ");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			_error(av[0], cnt, args[0]);
			free(args);
			exit(1);
		}
		exit(0);
	}
	else
	{
		if (status_main == 1)
			free(args[0]);

		free(args);
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}

/**
 * search_path - gets the path to execute commands
 * @environ: Environment variable
 * Return: token_path
 **/
char **search_path(char **environ)
{
	int position = 0;
	char **token_path;

	for (; environ[position] != NULL ; position++)
	{
		if (environ[position][0] == 'P' && environ[position][2] == 'T')
		{
			token_path = _which(environ[position]);
		}
	}
	return (token_path);
}
