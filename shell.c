#include "shell.h"

/**
 * main - entry point
 * @ac: number of arguments
 * @args: aray of argument
 * Return: 0 or status
 */

int main(int ac, char *args[])
{
	char *line = NULL;

	while (1)
	{
		line = read_line();
			if (!line)
				return (0);
		printf("%s", line);

	}

	return (0);
}
