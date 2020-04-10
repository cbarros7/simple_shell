#ifndef SIMPLESHELL_H
#define SIMPLESHELL_H

#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

void handle_signal(int signal);
int _stat(char *s);

/*int func_help(char **args);*/
int func_exit(char **args);
int func_printenv(char **args);

char *_which(char *args);
char *_getenv(const char *path);
char **sparse_env_str(char *line);
int child_process(char **args);

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strstr(char *str1, char *str2);

char *read_input(void);
char **sparse_str(char *line);
int execute(char **args);

typedef struct builtins{
	char *array_commands;
	int (*array_functions)(char **);
} builtins_t;

#endif
