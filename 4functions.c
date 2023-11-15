#include "shell.h"

void do_builtin(char **command, int *status)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, status);
	if (_strcmp(command[0], "env") == 0)
		print_environ(command, status);
}

/**
 * exit_shell - exit
 * @command: command
 * @status: status
 */

void exit_shell(char **command, int *status)
{
	freeStringArray(command);
	exit(*status);
}

/**
 *
 */

void print_environ(char **command, int *status)
{
	int i;
	(void) status;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	freeStringArray(command);
	*status = 0;
}
