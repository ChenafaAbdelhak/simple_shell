#include <unistd.h>
#include <stdlib.h>

/**
 * main - function that splits a string and 
 * returns an array of each word of the string
 * @av: is a NULL terminated array of strings
 * @ac: number of items in av
 *
 * Return: 0 seccess
*/

int main(int ac, char **av)
{
	(void)ac;
	(void)av;
	
	size_t Buffer_Size = 0;
	char *Buffer = NULL;
	int Num_Char = 0;
	int Size_Token = 0;

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

/**
 * Split _
 *
 *Return: array of strings
*/
char **Split(char *str)
{
	char *Token, **Tokens;
	int i = 0;

	Token = strok(str, "\t\n");
	while (Token != NULL)
	{
		i++;
		Tokens = realloc(Tokens, i * sizeof(char *));
		if (Tokens == NULL)
		{
			perror("realloc");
			exit(EXIT_FAILURE);
		}
		Tokens[i - 1] = Token;
		Token = strtok(NULL, "\t\n");
	}
}
