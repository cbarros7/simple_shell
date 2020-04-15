#include "simpleshell.h"

/**
 * _getenv - provides the value of the environment passed to it as arguement
 * @env: the environment to be passed as arguement
 * @name: string containing name of env variable
 * Return: an array which contains the value of the environment or)
 * on failure
 */
char *_getenv(char *name, char **env)
{
	char *tmp;
	char *path = NULL;
	char *found;
	int i;

	for (i = 0; env[i]; i++)
	{
		tmp = _strdup(env[i]);
		if (tmp == NULL)
		{
			free(tmp);
			return (NULL);
		}
		path = strtok(tmp, "=");
		if (_strcmp(path, name) == 0)
		{
			found = _strstr(env[i], "/");
		}
		free(tmp);
	}
	return (found);
}

/**
 * _which - identifies the path of the command(*args) that is being passed
 * to it
 * @args: the command that is being passed to it
 * @env: environment variable
 * Return: the complete path of the command or 0 on failure
 */
char *_which(char *args, char **env)
{
	char *buffer, *tokens, **dir, *sparse = ":=";
	char *file = NULL;
	int size, i = 0;

	buffer = _getenv("PATH", env);
	if (buffer == NULL)
		return (args);
	size = _count_point(buffer);

	dir = malloc(sizeof(char *) * size);
	if (dir == NULL)
	{
		perror("Error allocated memory");
		return (NULL);
	}

	tokens = strtok(buffer, sparse);

	while (tokens)
	{
		dir[i] = tokens;
		tokens = strtok(NULL, sparse);
		i++;
	}

	dir[i] = NULL;
	file = search_func(dir, args);
	free(dir);
	return (file);

}

/**
 * child_process - executes a command if the path of it is an executable file
 * @args: the command to be executed
 * @argv: external input arguements
 * @count: number of prompt
 * @env: environment variable
 * Return: 1
 */
int child_process(char **args, char **argv, int count, char **env)
{
	int status;
	char *path;
	int access;
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("error");
		return (1);
	}
	else if (pid == 0)
	{
		if (args != NULL)
		{
			path = _which(args[0], env);
			access = _access(path);
			if (execve(path, args, env) == -1)
			{
				_error(argv[0], count, args[0], access);
				free(path);
				free(args);
				exit(EXIT_FAILURE);
			}
			free(path);
		}
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
 * search_func - found directory
 * @dir: Double pointer at the directory
 * @cmd: command found
 * Return: command
 * On error, -1 is returned, and errno is set appropriately.
 */

char *search_func(char **dir, char *cmd)
{
	int i = 0;
	char *tmp;

	tmp = malloc(sizeof(char *) * 100);

	if (tmp == NULL)
		return (NULL);

	while (dir[i])
	{
		DIR *d;
		struct dirent *directory;

		d = opendir(dir[i]);

		if (d)
		{
			while ((directory = readdir(d)) != NULL)
			{
				if ((_strcmp(directory->d_name, cmd)) == 0)
				{
					_strcpy(tmp, dir[i]);
					_strcat(tmp, "/");
					_strcat(tmp, directory->d_name);
					closedir(d);
					return (tmp);
				}
			}
			closedir(d);
			i++;
		}


	}
	free(tmp);
	return (cmd);
}
