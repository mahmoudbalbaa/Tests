#include "main.h"

/**
 * _echo_print - Excute Normal Echo
 * @cmd: Parsed Command
 * Return: 0 Succes -1 Fail
 */

int _echo_print(char **cmd)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve("/bin/echo", cmd, environ) == -1)
			return (-1);
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		return (-1);
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}
