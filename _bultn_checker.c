#include "main.h"

/**
 * _bultn_checker - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */

int _bultn_checker(char **cmd)
{
	bul_t func[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"_history", NULL},
		{NULL, NULL}
		};
	int i = 0;

	if (*cmd == NULL)
		return (-1);

	while ((func + i)->command)
	{
		if (_strcmp_(cmd[0], (func + i)->command) == 0)
			return (0);
		i++;
	}

	return (-1);
}
