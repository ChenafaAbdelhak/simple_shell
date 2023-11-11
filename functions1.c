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
 *
 * Return: two d array of char
 */

char **tokenizer(char *line)
{
	char *token = NULL, *tmp = NULL;
	char **command = NULL;
	int cpt = 0, i = 0;

	if (!line)
		return (NULL);
	
	tmp = _strdup(line);
	token = strtok(tmp, " /t/n");
	if (!token)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (token)
	{
		cpt++;
		token = strtok(NULL, " /t/n");
	}
	free(tmp), tmp = NULL;

	command = malloc(sizeof(char *) * (cpt + 1));
	if (!command)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line ," /t/n");
	while (token)
	{
		command[i] = token;
		token = strtok(NULL, " /t/n");
		i++;
	}
	command[i] = NULL;

	return (command);
}

/**
 *
 *
 */

int _execute(char **command, char **args)
{
	pid_t child;
	int status;

	child = fork();
	if (child == 0)
	{
		if(execve(command[0], command, environ) == -1)
		{
			perror(args[0]);
		}
	}
	else
	{
		waitpid(child, &status, 0);
	}
	return (WEXITSTATUS(status));
}
