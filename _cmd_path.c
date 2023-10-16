#include "main.h"

/**
 * _cmd_path -  Search In $PATH For Excutable Command
 * @cmd: Parsed Input
 * Return: 1  Failure  0  Success.
 */

int _cmd_path(char **cmd)
{
	char *path, *value, *c_path;
	struct stat buf;

	path = _getenv_("PATH");
	value = _strtok_(path, ":");
	while (value != NULL)
	{
		c_path = _build_(*cmd, value);
		if (stat(c_path, &buf) == 0)
		{
			*cmd = _strdup_(c_path);
			free(c_path);
			free(path);
			return (0);
		}
		free(c_path);
		value = _strtok_(NULL, ":");
	}
	free(path);

	return (1);
}
