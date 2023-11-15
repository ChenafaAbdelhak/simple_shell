#include "shell.h"
/**
 * print_error - function that print Error
 * @name: string input
 * @command: string input
 * @i: index
 *
*/
void Print_ERR(char *name, char *command, int i)
{
	char *index, msg[] = ": not found\n";

	index = int_to_str(i);
	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, name, _strlen(index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, msg, _strlen(msg));
	free(index);
}
