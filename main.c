#include "main.h"

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int counter = 0, statue = 1, st = 0;

	if (argv[1] != NULL)
		_file_read(argv[1], argv);
	signal(SIGINT, sign_handle);
	while (statue)
	{
		counter++;
		if (isatty(STDIN_FILENO))
			print_prompt();
		input = _getline_();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = _cmd_prase(input);
		if (_strcmp_(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, counter);
		}
		else if (_bultn_checker(cmd) == 0)
		{
			st = _builtin_handl(cmd, st);
			_freeall_(cmd, input);
			continue;
		}
		else
		{
			st = _cmd_check(cmd, input, counter, argv);

		}
		_freeall_(cmd, input);
	}
	return (statue);
}
/**
 * _bultn_checker - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int _bultn_checker(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + i)->command)
	{
		if (_strcmp_(cmd[0], (fun + i)->command) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * _make_env - Creat Array of Enviroment Variable
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void _make_env(char **envi)
{
	int i;

	for (i = 0; environ[i]; i++)
		envi[i] = _strdup_(environ[i]);
	envi[i] = NULL;
}
