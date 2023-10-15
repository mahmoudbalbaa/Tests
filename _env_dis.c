#include "main.h"

/**
 * _env_dis - Display Enviroment Variable
 * @cmd:Parsed Command
 * @er:Statue of Last command Excuted
 * Return:Always 0
 */

int _env_dis(__attribute__((unused))char **cmd, __attribute__((unused))int er)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen_(environ[i]);
		write(1, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
	}

	return (0);
}
