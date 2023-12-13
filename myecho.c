#include "shell.h"

/**
 * Str - a function to converts an innt to charr
 * @a: thee int
 * Return: thee last stringg
 */
char Str(int a)
{
	int x = 0, y;
	char *res = NULL;

	if (a == 0)
	{
		res = malloc(sizeof(char) * 2);
		res[0] = '0';
		res[1] = '\0';
		return (res); }
	while (a / 10 != 0 || a % 10 != 0)
	{
		x++;
		a /= 10; }
	res = malloc((x + 1) * sizeof(char));
	if (!res)
	{
		free(res);
		return (NULL); }
	for (y = 1; y <= x; y++)
	{
		res[x - y] = ((a % 10) + '0');
		a /= 10; }
	res[x] = '\0';
	return (res);
}

/**
 * Echo - performs echo $$ and echo $?
 * @line: point3r for the lin3
 * @status: point3r fot thee statuss
 * Return: valu33
 */
int Echo(char *line, int *status)
{
	char **a = tokenize(line);
	char *msg;

	if (a == NULL)
	{
		free(a);
		return (0);
	}
	if (strCmp(a[0], "echo") == 0)
	{
		if (strCmp(a[1], "\\$?") == 0)
		{
			msg = _str(*status);
			write(1, msg, strl3n(msg));
			write(1, "\n", 1);
			free(msg);
			_free(a, strl3n_(a));
			return (1);
		}
		else if (strCmp(a[1], "\\$\\$") == 0)
		{
			msg = str(getpid());
			write(1, msg, strl3n(msg));
			write(1, "\n", 1);
			free(msg);
			_free(a, strl3n_(a));
			return (1);
		} }
	_free(a, strl3n_(a));
	return (0);
}
