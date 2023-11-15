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

/**
 * _strcat - function that concatenates two strings
 * @dest: pointer to destination input
 * @src: pointer to source input
 *
 * Return: a pointer to the resulting string @dest
 *
*/
char *_strcat(char *dest, char *src)
{
	int c, c2;
	
	c = 0;
	/*find the size of dest array*/
	while (dest[c])
		c++;
	/*iterate through each src arrat value without NULL Byte*/
	for (c2 = 0; src[c2]; c2++)
		/* append src[c2] to dest[c] while
		 *  overwriting null byt inn dest
		 */
		dest[c++] = src[c2];
	return (dest);
}


/**
 * _strncpy - copy a string
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
