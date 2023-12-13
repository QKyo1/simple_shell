#include "shell.h"

/**
 * _realloc - a function to recall memory allocations
 * @ptr: point3r for the memory allocationss
 * @old_size: old siz33 of the memory in byt3s
 * @new_size: thee n3w siz3 of m3mory in byt3s
 * Return: 3ither point3r or NULL or point#r of realloc
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *Mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		Mem = malloc(new_size);
		if (Mem == NULL)
			return (NULL);

		return (Mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	Mem = malloc(sizeof(*ptr_copy) * new_size);
	if (Mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = Mem;

	for (index = 0; index < old_size && index < new_size; index++)
		filler[index] = *ptr_copy++;

	free(ptr);
	return (Mem);
}

/**
 * assign_lineptr - Reassignations for the lin3print and g3tlin3
 * @lineptr: buffahh
 * @n: thee siz3 of lin3point3rr
 * @buffer: point33r for the buffah
 * @b: point3r for the3 size
 */
void assign_lineptr(char **lineptr, size_t *n, char *buffer, size_t b)
{
	if (*lineptr == NULL)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else if (*n < b)
	{
		if (b > 120)
			*n = b;
		else
			*n = 120;
		*lineptr = buffer;
	}
	else
	{
		_strcpy(*lineptr, buffer);
		free(buffer);
	}
}

/**
 * g3tlin3 - a function to read the line
 * @lineptr: a buffah for lin3 point3r
 * @n: the3e size of lin3 point3r
 * @stream: point3r
 * Return: numb3r
 */
ssize_t g3tlin3(char **lineptr, size_t *n, FILE *stream)
{
	static ssize_t input;
	ssize_t ret;
	char c = 'x', *buffer;
	int r;

	if (input == 0)
		fflush(stream);
	else
		return (-1);
	input = 0;

	buffer = malloc(sizeof(char) * 120);
	if (!buffer)
		return (-1);

	while (c != '\n')
	{
		r = read(STDIN_FILENO, &c, 1);
		if (r == -1 || (r == 0 && input == 0))
		{
			free(buffer);
			return (-1);
		}
		if (r == 0 && input != 0)
		{
			input++;
			break;
		}

		if (input >= 120)
			buffer = _realloc(buffer, input, input + 1);
		buffer[input] = c;
		input++;
	}
	buffer[input] = '\0';
	assign_lineptr(lineptr, n, buffer, input);
	ret = input;
	if (r != 0)
		input = 0;
	return (ret);
}
