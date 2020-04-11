#include "SimpleShell.h"

/**
 * search_func - found directory
 * @folder: Double pointer at the directory
 * @command: command found
 * Return: command
 * On error, -1 is returned, and errno is set appropriately.
 */

char *search_func(char **dir, char *cmd)
{
	int i = 0;
	char *tmp;

	tmp = malloc (sizeof(char *) * 100);

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
	return(cmd);

}