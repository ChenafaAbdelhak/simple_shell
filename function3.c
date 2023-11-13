#include "shell.h"
/**
 * _getenv - gets an environment variable
 * @value: string variable
 *
 * return: NULL
*/
char *_getenv(char *value)
{
	char * temp, *env, *var, *elemnt;
	int i;

	for (i = 0; environ[i]; i++)
	{
		temp = _strdup(environ[i]);
		elment = strtok(temp,"=");
		if (_strcmp(elemnt, value) == 0)
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
