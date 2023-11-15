#include "shell.h"
/**
 * print_error - function
 * @name: string input
 * @prompt: string input
 * @i: index
 *
*/
void print_error(char *name, char *command, int i)
{
	char index;
	msg[] = ": not found";

	index = _itoa
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, name, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, msg, _strlen(index));
	free(index);
}
