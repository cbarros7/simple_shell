#include "SimpleShell.h"

void handle_signal(int signal)
{
	(void) signal;
	printf("\n$ ");
	fflush(stdout);			/* FUERZA DE LA EJECUCCIÓN DE LA FUNCION DE ESCRITURA SUBYACENTE PARA LA SALIDA ESTANDAR*/
}

int _stat(char *str)
{
	struct stat var;

	if (stat(str, &var) == 0)
		return (0);
	return (-1);
}
