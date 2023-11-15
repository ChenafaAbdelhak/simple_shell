#include "shell.h"

/**
 * main - entry point
 * @ac: number of arguments
 * @args: aray of argument
 * Return: 0 or status
 */

int main(int ac, char *args[])
{
	char *line = NULL, **command = NULL;
	int status = 0, index = 0;
	(void) ac;
	(void) args;

	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;
		command = tokenizer(line);
		if (!command)
			continue;
		status = _execute(command, args, index);
	}
	return (status);
}
