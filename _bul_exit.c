#include "main.h"
/**
 * _bul_exit - Exit Statue Shell
 * @cmd: Parsed Command
 * @input: User Input
 * @argv:Program Name
 * @c:Excute Count
 * Return: Void (Exit Statue)
 */
void  _bul_exit(char **cmd, char *input, char **argv, int c)
{
	int st, i = 0;

	if (cmd[1] == NULL)
	{
		free(input);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	while (cmd[1][i])
	{
		if (_isalpha_(cmd[1][i++]) != 0)
		{
			_perror_(argv, c, cmd);
			break;
		}
		else
		{
			st = _atoi_(cmd[1]);
			free(input);
			free(cmd);
			exit(st);
		}
	}
}
