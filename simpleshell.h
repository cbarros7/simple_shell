#ifndef _SIMPLESHELL_H_
#define _SIMPLESHELL_H_
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>
#define TOK_BUFSIZE 64
#define TOK_DELIM " \t\r\n\a"
extern char **environ;

void handle_signal(int signal);
int _stat(char *s);
int *_error(char *argv, int count, char *args, int access);

int func_exit(char **args);
int func_printenv(char **args);

char *_which(char *args);
char *_getenv(char *path);
char *search_func(char **dir, char *cmd);
int child_process(char **args, char **argv, int count);
int _access(char *filename);

char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strstr(char *str1, char *str2);
char *_strdup(char *str);
char *_itoa(int num, int base);

char *read_input(void);
char **sparse_str(char *line);
int execute(char **args, char **argv, int count, char *line);
void prompt(void);

void *_realloc(void *ptr, unsigned int new_size);
int _count_point(char *buffer);

#endif
