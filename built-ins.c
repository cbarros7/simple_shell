#include "SimpleShell.h"
/*
   int func_help(char **args)
   {
   (void) args;
   char *array_commands[] = {
   "help",
   "exit"
   };
   char *array_help[] = {
   "help - displays this menu",
   "exit - exits child program and goes back to parent. use-> <exit>"
   };
   unsigned int i = 0;
   printf("Welcome to help menu\nThese are the different commands\n");
   while (i < (sizeof(array_commands) / sizeof(char **)))
   {
   printf(" %s\n", array_help[i]);
   i++;
   }
   return (1);
   }
 */

int func_exit(char **args)
{
	(void) args;
	exit(0);
}

int func_printenv(char **args)
{
	char **array = environ;
	int i;
	(void) args;

	for (i = 0; array[i]; i++)
	{
		printf("%s\n", array[i]);
	}

	return (1);
}