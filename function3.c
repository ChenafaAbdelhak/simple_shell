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
int main(void)
{
	printf("%s\n", _getenv("PWDb"));
	return (0);
}
