#include "shell.h"

void do_builtin(char **command, int status)
{
	if (_strcmp(command[0], "exit") == 0)
		exit_shell(command, status);
		
}

/**
 * exit_shell - exit
 * @command: command
 * @status: status
 */

void exit_shell(char **command, int status)
{
	freeStringArray(command);
	exit(status);
}
