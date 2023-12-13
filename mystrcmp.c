#include "shell.h"

/**
 * strCmp - a funtion to compaar3
 * @s1: firts valu3
 * @s2: second3 value
 * Return: s1 or s2
 */

int strCmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
