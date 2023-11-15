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
char **tokenizer(char *line);
int _execute(char **command, char **args);
void free2DArray(char **array);
char *_getenv(char *value);
char *_getpath(char *command);
char *_strncpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
void freeStringArray(char **array);
char *_strdup(char *str);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
