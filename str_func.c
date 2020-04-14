#include "simpleshell.h"

/**
 * *_strstr - locates a substring
 * @str1: string one
 * @str2: string two
 *
 * Return: pointer to the beginning of the located substring
 * or NULL if the substring is not found
 */
char *_strstr(char *str1, char *str2)
{
	int i, j;

	for (i = 0; str1[i] != '\0'; i++)
	{
		for (j = 0; str2[j] != '\0'; j++)
		{
			if (str1[i + j] != str2[j])
				break;
		}
		if (!str2[j])
			return (&str1[i]);
	}
	return (NULL);
}

/**
 * _strlen - returns a string
 * @s: integer to be used
 * Return: length of string
 */
int _strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return ((i + 1));
}

/**
 * *_strcpy - copies a string pointed to by src to dest
 * @src: variale where string will be copied from
 * @dest: variable that string will be copied to
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int p;

	for (p = 0; src[p] != '\0'; p++)
	{
		dest[p] = src[p];
	}
	dest[p] = '\0';

	return (dest);
}

/**
 * *_strcat - concatenates two strings
 * @src: variable containing string to be concatenated
 * @dest: variable containing string to be concatenated to
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{

	int dest_c = 0;
	int src_c = 0;

	while (dest[dest_c] != '\0')
	{
		dest_c++;
	}

	while (src[src_c] != '\0')
	{
		dest[dest_c] = src[src_c];
		src_c++;
		dest_c++;
	}

	dest[dest_c] = '\0';

	return (dest);
}

/**
 * _strcmp - compare two strings
 * @s1: string one
 * @s2: string two
 * Return: returns an integer less  than,  equal  to,  or
 * greater  than zero if s1 is found, respectively, to be
 * less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
	char *p1 = s1;
	char *p2 = s2;

	while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	return (*p1 - *p2);
}

