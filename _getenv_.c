#include "main.h"

/**
 * _getenv_ - Gets The Value Of Enviroment Variable By Name
 * @name: Environment Variable Name
 * Return: The Value of the Environment Variable Else NULL.
 */

char *_getenv_(char *name)
{
	size_t nl, vl;
	char *value;
	int i, x, j;

	nl = _strlen_(name);
	for (i = 0 ; environ[i]; i++)
	{
		if (_strncmp_(name, environ[i], nl) == 0)
		{
			vl = _strlen_(environ[i]) - nl;
			value = malloc(sizeof(char) * vl);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = nl + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';

			return (value);
		}
	}

	return (NULL);
}
