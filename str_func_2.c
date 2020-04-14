#include "SimpleShell.h"

/**
 * _strdup - copes a string to another
 * @str: the array
 * Return: pointer of sting copied
 */
char *_strdup(char *str)
{
	int i, j;
	char *s;

	if (str == NULL)
		return (0);
	for (i = 0; str[i]; i++)
		;
	s = malloc(i + 1);
	if (!s)
		return (NULL);
	for (j = 0; j < i; j++)
	{
		s[j] = str[j];
	}
	return (s);
}

/**
 * _strncpy_curr - copies a string
 * @dest: variable where string will be copied
 * @src: variable that will provide the string
 * @n: size limit of bytes that can be coppied
 * Return: dest
 */
char *_strncpy_curr(char *dest, char *src, int n)
{
	int i, j = 0;

	i = 2;
	while (src[i] != '\0' && i < n)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';

	return (dest);
}
