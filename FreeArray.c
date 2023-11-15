#include "shell.h"
/**
 * freeStringArray - function that free an array of string
 * @array: input
 * Return: nothing used for freeing memory
 */
void freeStringArray(char **array)
{
	int i;

	if (!array)
		return;
	for (i = 0; array[i]; i++)
	{
		free(array[i]);
		array[i] = NULL;
	}
	free(array);
	array = NULL;
}
