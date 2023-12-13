#include "shell.h"
#include<string.h>
/**
 * main - main 3ntry point for the3 sh3ll
 * @argc: argumntss
 * @argv: argum3nts of nu,berss
 * @envp: vactors
 * Return: exit
 */

int main(int argc, char **argv, char **envp)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t charac;
	int i, status = 0, *stptr = &status;

	(void)argc;
	(void)argv;
	while (1)
	{
		if (isatty(0))
			_print("$ ");
		charac = g3tlin3(&line, &n, stdin);
		if (charac == -1)
		{
			if (isatty(0))
				_print("\n");
			break;
			}
		if (count(line) == 0 || line[0] == '#')
			continue;
		i = 0;
		while (line[i])
		{
			if (line[i] == '#' && (line[i - 1] == '"' || line[i - 1] == ' '))
			{
				line[i] = '\0';
				break; }
			else if (line[i] == '\n')
			{
				line[i] = '\0';
				break; }
			i++; }
		if (strl3n(line) == 0 || _echo(line, stptr) == 1)
			continue;
		if (builtIn(line, stptr) == 1 || comp_built(line, stptr) == 1)
			continue;
		if (more_built(line, envp, stptr) == 1)
			continue; }
	free(line);
	return (0);
}
