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
	int status = 0;
	(void) ac;
/*
	while (1)
	{
		line = read_line();
			if (!line)
			{
				if (isatty(STDIN_FILENO))
					write(STDOUT_FILENO, "\n", 1);
				return (status);
			}
		command = tokenizer(line);
		if (!command)
			continue;
		status = _execute(command, args);*/
		
		printf("ffff");
		command = tokenizer("how are you betty");

	

	return (0);
}
