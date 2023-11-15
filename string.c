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

/**
 * reverse_string - reverses the characters in the array
 * @str: character
 * @len: size
*/

void reverse_string(char *str, int len)
{

	for (int i = 0, j = len - 1; i < j; i++, j--)
	{
		char temp = str[i];

		str[i] = str[j];
		str[j] = temp;
	}
}

/**
 * *int_to_str - converts an integer (n) to a string
 * @num: integer input
 * Return: buffer
*/

char *int_to_str(int num)
{
	char buffer[20];
	int index = 0;

	do {
		buffer[index++] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	buffer[index] = '\0';
	reverse_string(buffer, index);
	return (strdup(buffer));
}
