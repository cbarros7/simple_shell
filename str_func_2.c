#include "simpleshell.h"

/**
 * _strdup - copes a string to another
 * @str: the array
 * Return: pointer of sting copied
 */
char *_strdup(char *str)
{
	int i, j;
	char *s = NULL;

	if (str == NULL)
		return (0);
	for (i = 0; str[i]; i++)
		;
	i++;
	s = malloc(i * sizeof(char *));
	if (!s)
		return (NULL);
	for (j = 0; j < i; j++)
	{
		s[j] = str[j];
	}
	return (s);
}

/**
 * _itoa - integer to ascii
 * @num: num
 * @base: base
 * Return: char
 * Reference: https://gist.github.com/narnat/95733cd0ad7bfac0d90697292914c407
 **/
char *_itoa(int num, int base)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (num < 0)
	{
		n = -num;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do      {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
