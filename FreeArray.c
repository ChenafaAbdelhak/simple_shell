#include "shell.h"
<<<<<<< HEAD
/*
 * freeStringArray- function that free an array of string
=======
/**
 * freeStringArray - function that free an array of string
>>>>>>> a38ce8a983f956c74a409ca7ce13b0262fe8d21c
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
