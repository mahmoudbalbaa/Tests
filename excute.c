#include "main.h"

/**
 * _builtin_handl - Handle Builtin Command
 * @cmd: Parsed Command
 * @er:statue of last Excute
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int _builtin_handl(char **cmd, int er)
{
	 bul_t bil[] = {
		{"cd", _cd},
		{"env", _env_dis},
		{"help", _help},
		{"echo", _echo},
		{"_history", ___his_dis},
		{NULL, NULL}
	};
	int i = 0;

	while ((bil + i)->command)
	{
		if (_strcmp_(cmd[0], (bil + i)->command) == 0)
		{
			return ((bil + i)->fun(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * _cmd_check - Excute Simple Shell Command (Fork,Wait,Excute)
 *
 * @cmd:Parsed Command
 * @input: User Input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int _cmd_check(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp_(*cmd, "./", 2) != 0 && _strncmp_(*cmd, "/", 1) != 0)
		{
			_cmd_path(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			_errorprint(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * sign_handle - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void sign_handle(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
