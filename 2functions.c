#include "shell.h"

/**
 * _strdup - creates an array of chars,
 * and initializes it with a specific char
 *@str : size of the array
 *
 *Return: void
 */
char *_strdup(char *str)
{
	char *ret, *s;
	int i;

	if (str == NULL)
		return (NULL);
	i = _strlen(str);
	s = (char *)malloc(_strlen(str) * sizeof(char) + 1);
	if (s == 0)
		return (NULL);
	ret = s;
	while (i > 0)
	{
		*s = *str;
		s++;
		str++;
		i--;
	}
	return (ret);
}

/**
 * _strlen - calculete length
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
