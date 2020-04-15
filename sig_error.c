#include "simpleshell.h"

/**
 * handle_signal - prints new line and prompt when CTRL + C is passed as input
 * @signal: name of sig
 */
void handle_signal(int signal)
{
	char *prompt = {"\n$ "};
	(void) signal;

	write(STDOUT_FILENO, prompt, _strlen(prompt));
	fflush(stdout);
}

/**
 * _stat - get file status
 * @cmd: pointo with commands
 * @path: location of each directory
 * Return: 1 on success
 **/
int _stat(char **cmd, char **path)
{
	char *conc_str = NULL, *new_concat = NULL;
	int count = 1;

	struct stat sb;

	for (; path[count] != NULL ; count++)
	{
		conc_str = str_concat(path[count], "/"); /*ir concatenando los / al path*/
		new_concat = str_concat(conc_str, cmd[0]); /*concatenar el comando*/

		if (stat(new_concat, &sb) == 0) /*arroja el estado del nuevo path*/
		{
			cmd[0] = new_concat;
			free(conc_str);
			free(path[0]);
			free(path);
			return (1);
		}
		free(conc_str);
		free(new_concat);
	}
	free(path[0]);
	free(path);
	return (0);
}

