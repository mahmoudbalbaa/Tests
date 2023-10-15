#include "main.h"

/**
* _getline_ - Read The Input By User From Stdin
* Return: Input
*/

char *_getline_()
{
	int i, buffsize = BUFSIZE, rd;
	char c = 0;
	char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);

		rd = read(STDIN_FILENO, &c, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}

		buff[i] = c;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}

		if (i >= buffsize)
		{
			buff = _realloc_(buff, buffsize, buffsize + 1);
			if (buff == NULL)
				return (NULL);
		}
	}
	buff[i] = '\0';
	_hash_handl(buff);

	return (buff);
}
