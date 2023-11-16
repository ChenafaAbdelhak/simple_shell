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
	char *ret = NULL, *s = NULL;
	int i;

	if (str == NULL)
		return (NULL);
	i = _strlen(str);
	s = malloc((_strlen(str) * sizeof(char)) + 1);
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
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * _strncpy - copy a string
 * @dest: input value
 * @src: input value
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src)
{
	char *ptr;
	int len = 0, i = 0;

	ptr = dest;
	while (src[len] != '\0')
		len++;
	while (i <= len)
	{
		dest[i] = src[i];
		i++;
	}
	return (ptr);
}

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
	int s;

	s = 0;
	while (s1[s] != '\0' && s2[s] != '\0')
	{
		if (s1[s] != s2[s])
			return (s1[s] - s2[s]);
		s++;
	}
	return (0);
}
