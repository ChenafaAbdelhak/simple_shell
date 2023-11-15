#include "shell.h"

/**
 * _strcat - concatinate two s
 * @dest: destination
 * @src: source
 * Return: pointer to dest
 */

char *_strcat(char *dest, char *src)
{
	char *tmp = dest;

	while (*dest != '\0')
		dest++;
	*dest  = *src;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
			if (*src == '\n')
				*dest = *src;
	}
	return (tmp);
}

/**
 * _strcpy - copy
 * @dest: destination
 * @src: source
 * Return: dest
 */

char *_strcpy(char *dest, char *src)
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
