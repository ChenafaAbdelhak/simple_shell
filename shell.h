#ifndef SHELL_HEADER
#define SHELL_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

extern char **environ;

char *read_line(void);
char *_strdup(char *str);
char **tokenizer(char *line);
int _strlen(char *s);
int _execute(char **command, char **args);


#endif