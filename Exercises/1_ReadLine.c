#include <stdio.h>
#include <unistd.h>
/**
 * main - prints "$ ", wait for the user to enter
 * a command, prints it on the next line.
 * @ac: number of items in av
 * @av: terminated array of string
 * Return: 0 success
*/

int main(int ac, char **av)
{
	(void)ac;
	size_t Buffer_Size = 0;
	char *Buffer = NULL;
	int Num_Char = 0;

	write(1, "$ ", 2);/*2 for two character $ and space*/
	Num_Char = getline(&Buffer, &Buffer_Size, stdin);
	/* EOF end of file or / -1*/
	if (Num_Char == EOF)
		perror("Getline");
	/* delete space*/
	Buffer[Num_Char -1] = '\0';
	printf("%s\n", Buffer);

	return (0);
}
