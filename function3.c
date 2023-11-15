#include "shell.h"
/**
 * _getenv - gets an environment variable
 * @value: string variable
 *
 * Return: NULL 0 or env
*/
char *_getenv(char *value)
{
	char *temp, *env, *var, *element;
	int i;

	for (i = 0; environ[i]; i++)
	{
		temp = _strdup(environ[i]);
		element = strtok(temp, "=");
		if (_strcmp(element, value) == 0)
		{
			var = strtok(NULL, "\n");
			env = _strdup(var);
			free(temp);
			return (env);
		}
		free(temp), temp = NULL;
	}
	return (NULL);
}
/**
 * *_getpath - function that prints each 
 * directory contained in the the environment
 * variable PATH
 * @command: character
 * Return: NULL / prompt
 *
*/
char *_getpath(char *command)
{
	char *env_path, *prompt, *dir;
	struct stat st;

	dir = strtok(env_path, ":");
	while(dir)
	{
		prompt = malloc(_strlen(dir) + _strlen(command) + 2);
		if (prompt)
		{
			_strncpy(prompt, dir);
			_strcat(prompt, "/");
			_strcat(prompt, command);
			if (stat(prompt, &st) == 0)
			{
				free(env_path);
				return (prompt);
			}
			free(prompt), prompt = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(env_path);
	return (NULL);
}
int main(int ac, char **av)
{
	char *prompt;
	prompt = _getpath(av[1]);
	if(prompt)
		printf("%s\n", prompt);
	else
		printf("does not exist");
}
