#include "shell.h"

/**
 * strl3n - a function for s
 * @s: point33r
 * Return: bla
 */

size_t strl3n(const char *s)
{
	size_t i = 0;

	while (*s != '\0')
	{
		i++;
		s++;
	}
	return (i);
}
