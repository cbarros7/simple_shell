#include "simpleshell.h"

/**
 *_puts - prints a string
 *@str: A pointer to an int that will be updated
 *
 *Return: void
 */
void _puts(char *str)
{
	int n;

	for (n = 0 ; str[n] != '\0' ; n++)
	{
		_putchar(str[n]);
	}
	_putchar('\n');
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
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 *str_concat - back a pointer to array
 *@s1: Array one
 *@s2: Array two
 *Return: Always an array dinamic
 */
char *str_concat(char *s1, char *s2)
{
	char *dst;
	unsigned int i, j, size;

	/*If the array is empty*/
	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	/*count size total*/
	size = (_strlen(s1) + _strlen(s2) + 1);

	/*malloc*/
	dst = (char *) malloc(size * sizeof(char));

	if (dst == 0)
	{
		return (NULL);
	}

	/*Concatenate arrays*/
	for (i = 0; *(s1 + i) != '\0'; i++)
		*(dst + i) = *(s1 + i);

	for (j = 0; *(s2 + j) != '\0'; j++)
	{
		*(dst + i) = *(s2 + j);
		i++;
	}
	dst[i] = '\0';

	return (dst);
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

