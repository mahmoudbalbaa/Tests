#include "main.h"

/**
 * _cd - Change Dirctory
 * @cmd: Parsed Command
 * @er: Statue Last Command Excuted
 * Return: 0 Succes 1 Failed (For Old Pwd Always 0 Case No Old PWD)
 */

int _cd(char **cmd, __attribute__((unused))int er)
{
	int v = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		v = chdir(getenv("HOME"));
	else if (_strcmp_(cmd[1], "-") == 0)
		v = chdir(getenv("OLDPWD"));
	else
		v = chdir(cmd[1]);

	if (v == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (v != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}

	return (0);
}
