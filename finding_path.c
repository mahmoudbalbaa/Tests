#include "main.h"

/**
 * _cmd_path -  Search In $PATH For Excutable Command
 * @cmd: Parsed Input
 * Return: 1  Failure  0  Success.
 */
int _cmd_path(char **cmd)
{
	char *path, *value, *cmd_path;
	struct stat buf;

	path = _getenv_("PATH");
	value = _strtok_(path, ":");
	while (value != NULL)
	{
		cmd_path = _build_(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = _strdup_(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok_(NULL, ":");
	}
	free(path);

	return (1);
}
/**
 * _build_ - Build Command
 * @token: Excutable Command
 * @value: Dirctory Conatining Command
 *
 * Return: Parsed Full Path Of Command Or NULL Case Failed
 */
char *_build_(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = _strlen_(value) + _strlen_(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat_(cmd, value);
	cmd = _strcat_(cmd, "/");
	cmd = _strcat_(cmd, token);

	return (cmd);
}
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
