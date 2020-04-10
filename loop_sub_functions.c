#include "SimpleShell.h"

/**
 * _getenv - provides the value of the environment passed to it as arguement
 * @env: the environment to be passed as arguement
 * Return: an array which contains the value of the environment or)
 * on failure
 */
char *_getenv(const char *env)
{
	char **environment;
	char *tmp, *token;
	int i;

	environment = environ;
	for (; *environment; ++environment)
	{
		tmp = *environment;
		token = strtok(tmp, "=");
		if (token == NULL)
			return (0);
		if (_strlen(token) != _strlen(env))
			continue;
		for (i = 0; i < _strlen(env); i++)
		{
			if (env[i] != tmp[i])
			{
				break;
			}
			else if (env[i] == tmp[i])
				return (strtok(NULL, "="));
		}
	}
	return (0);
}

/**
 * _which - identifies the path of the command(*args) that is being passed
 * to it
 * @args: the command that is being passed to it
 * Return: the complete path of the command or 0 on failure
 */
char *_which(char *args)
{
	char *tmp, **path, *sparse;
	int size, i, size_path;

	size = _strlen((const char *)args);
	if (args == NULL)
		return (0);

	sparse = _getenv("PATH");
	path = sparse_env_str(sparse);
	for (i = 0; path[i] != NULL; i++)
	{
		size_path = _strlen(path[i]);
		tmp = malloc(size_path + size + 1);
		if (tmp == NULL)
			return (0);
		tmp = _strcpy(tmp, path[i]);
		tmp = _strcat(tmp, "/");
		tmp = _strcat(tmp, (char *)args);

		if (_stat(tmp) == 0)
		{
			return (tmp);
		}
	}
	return (0);
}

/**
 * child_process - executes a command if the path of it is an executable file
 * @args: the command to be executed
 * Return: 1
 */
int child_process(char **args)
{
	pid_t pid;
	int status;
	char *path;

	pid = fork();
	if (pid  < 0)
	{
		printf("error\n");
	}
	else if (pid == 0)
	{
		if (args != NULL)
		{
			path = _which(args[0]);
			execve(path, args, environ);
			execve(args[0], args, environ);
			if (execve(path, args, NULL) == -1)
			{
				printf("error: command not found\n");
				exit(EXIT_FAILURE);
			}
		}
		free(path);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}

/**
 * sparse_env_str - separates the value of the env being passed to it
 * into strings
 * @line: array to be sparsed
 * Return: an array of strings containing the paths
 */
char **sparse_env_str(char *line)
{
	int bufsize = TOK_BUFSIZE, posicion = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token, **tokens_backup;
	char *delim = {":"};

	if (!tokens)
	{
		printf("error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, delim);
	while (token != NULL)
	{
		tokens[posicion] = token;
		posicion++;
		if (posicion >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens_backup = tokens;
			/*CONTAR LOS DOS :*/
			tokens = _realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				free(tokens_backup);
				printf("error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[posicion] = NULL;
	return (tokens);
}
