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
 * reverse_string - reverses the characters in the array
 * @input: character
 * @length: size
*/

void reverse_string(char *input, int length)
{
	int begin = 0;
	int last = length - 1;

	while (begin < last)
	{
		char temp = input[begin];

		input[begin] = input[last];
		input[last] = temp;
		begin++;
		last--;
	}
}
/**
 * *int_to_str - converts an integer(n)
 * to a string
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
