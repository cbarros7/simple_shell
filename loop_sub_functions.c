#include "SimpleShell.h"

char *_getenv(const char *path)
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
		if (_strlen(token) != _strlen(path))
			continue;
		for (i = 0; i < _strlen(path); i++)
		{
			if (path[i] != tmp[i])
			{
				break;
			}
			else if (path[i] == tmp[i])
				return (strtok(NULL, "="));
		}
	}
	return (0);
}

char *_which(char *args)
{
	//char *comp;
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

		//comp = _strstr(tmp, args);
		//tmp = comp;

		if (_stat(tmp) == 0)
		{
			return (tmp);
		}
	}
	return (0);
}

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
			tokens = _realloc(tokens, bufsize * sizeof(char *)); /*CONTAR LOS DOS :*/
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
