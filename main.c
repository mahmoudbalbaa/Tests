#include "main.h"

/**
 * main - Simple Shell
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
		_history(input);
		cmd = _cmd_prase(input);
		if (_strcmp_(cmd[0], "exit") == 0)
		{
			_bul_exit(cmd, input, argv, counter);
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
