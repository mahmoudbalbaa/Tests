#include "main.h"

/**
 * _echo - Excute Echo Cases
 * @st:Statue Of Last Command Excuted
 * @cmd: Parsed Command
 * Return: Always 0 Or Excute Normal Echo
 */

int _echo(char **cmd, int st)
{
	char *path;
	unsigned int  pid = getppid();

	if (_strncmp_(cmd[1], "$?", 2) == 0)
	{
		_print_num_in(st);
		PRINTER("\n");
	}
	else if (_strncmp_(cmd[1], "$$", 2) == 0)
	{
		_print_num(pid);
		PRINTER("\n");
	}
	else if (_strncmp_(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv_("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);
	}
	else
		return (_echo_print(cmd));

	return (1);
}
