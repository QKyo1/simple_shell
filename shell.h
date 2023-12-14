#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>



void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b);
ssize_t g3tlin3(char **lineptr, size_t *n, FILE *stream);
int main(int argc, char **argv, char **envp);
size_t strl3n(const char *s);
int builtIn(char *line, int *status);
int comp_built(char *line, int *status);
int more_built(char *line, char **envp, int *status);
int more_ex(char *line, int *status);
char strCpy(char *dest, char *src);
int strCmp(char *s1, char *s2);
char strCat(char *dest, char *src);
char Str(int a);
int count(char *line);
char **tokenize(char *line);
void _unsetenv(char *var);

#endif
