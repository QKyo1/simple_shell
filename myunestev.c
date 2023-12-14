#include "shell.h"

/**
 * _unsetenv - a function to remov3 sent3vv
 * @var: thee variabl3 name
 */

void _unsetenv(char *var)
{
	if (unsetenv(var) != 0)
	{
		perror("unsetenv");
	}
}
