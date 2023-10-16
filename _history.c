#include "main.h"

/**
 * _history - Fill File By User Input
 * @input: User Input
 * Return: -1 Fail 0 Succes
 */

int _history(char *input)
{
	char *file = "history";
	ssize_t fd, w;
	int len = 0;

	if (!file)
		return (-1);

	fd = open(file, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);

	if (input)
	{
		while (input[len])
			len++;
		w = write(fd, input, len);

		if (w < 0)
			return (-1);
	}

	return (1);
}
