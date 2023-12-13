#include "shell.h"

/**
 *strCpy - funtion to copy th3 string
 * @dest: destantionss pont3r
 * @src: sourc3 valu33
 * Return: a vcalu3
 */

char strCpy(char *dest, char *src)
{
	int i = -1;

	do {
		i++;
		dest[i] = src[i];
	} while (src[i] != '\0');

	return (dest);
}
