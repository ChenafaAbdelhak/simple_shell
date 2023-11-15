#include "shell.h"

/**
 * read_line - read a line from stdin
 * Return: the line as a *char
 *
 */

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	n = getline(&line, &len, stdin);
	if (n == -1)
		return (NULL);
	return (line);
}


/**
 * tokenizer - tokenizer
 * @line: line
 * Return: two d array of char
 */

char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL, *DELIM = " \t\n";
	char **command = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);

	tmp = _strdup(line);
	token = strtok(tmp, DELIM);
	if (!token)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		cpt++;
		token = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;

	command = (char **) malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, DELIM);
	while (token)
	{
		command[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	command[i] = NULL;

	return (command);
}

/**
 * _execute - execute a command
 * @command: the command
 * @args: argv of main
 * @index: integer input
 * Return: exit status
 */

int _execute(char **command, char **args, int index)
{
	pid_t child;
	char *prompt;
	int status;

	prompt = _getpath(command[0]);
	if (!prompt)
	{
		Print_ERR(args[0], command[0], index);
		freeStringArray(command);
		return (0);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(prompt, command, environ) == -1)
		{
			free(prompt), prompt = NULL;
			freeStringArray(command);
			perror(args[0]);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		free(prompt), prompt = NULL;
		freeStringArray(command);
	}
	return (WEXITSTATUS(status));
}
