#include <stdio.h>
#include <unistd.h>

/**
 * main - a program that prints all the arguments,
 * without using ac
 * @av: array of string
 * @ac: the number of items in av
 * Return: 0
 */
int main(int ac, char **av)
{
	/* Using (void) to suppress the "unused ac variable" warning */
	(void) ac;
	int Arg_index = 0;

	while (av[Arg_index])
	{
		printf("%s\n", av[Arg_index]);
		Arg_index++;
	}
	return (0);
}
