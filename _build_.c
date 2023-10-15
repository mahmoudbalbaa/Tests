#include "main.h"

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
