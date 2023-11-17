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
	if (n < 0)
	{
		free(line), line = NULL;
		return (NULL);
	}
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
	while (token != NULL)
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
 * @argv: argv of main
 * @index: integer input
 * Return: exit status
 */

int _execute(char **command, char **argv, int index)
{
	pid_t child;
	char *prompt;
	int status;
	(void) prompt;

	/*prompt = _getpath(command[0]);*/
	if (!command)
	 {
		Print_ERR(argv[0], command[0], index);
		freeStringArray(command), command = NULL;
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			/*free(prompt), prompt = NULL;*/
			freeStringArray(command), command = NULL;
			perror(argv[0]);
			exit(127);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		/*free(prompt), prompt = NULL;*/
		freeStringArray(command);
	}
	return (WEXITSTATUS(status));
}

/**
 * is_builtin - is it a builtin function
 * @command: command
 * Return: zero or one
 */

int is_builtin(char *command)
{
	char *builtin[] = {"exit", "env"};
	int i;

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(builtin[i], command) == 0)
			return (1);
	}
	return (0);
}

int main(int ac, char **args)
{
	char **tok, a[] = "ls -la";
	int i, stat;
	(void) ac;

	

	tok = tokenizer(a);
	stat = _execute(tok, args,1);

	for (i = 0; tok[i]; i++)
		printf("%s\n", tok[i]);
	printf("%d", stat);


	return (0);
}
