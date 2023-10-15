#include "main.h"
/**
 * _file_read - Read Command From File
 * @filename:Filename
 * @argv:Program Name
 * Return: -1 or  0
 */

void _file_read(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		_treat_file(line, counter, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * _treat_file - PARSE Check Command Fork Wait Excute in Line of File
 * @line: Line From A File
 * @counter:Error Counter
 * @fp:File Descriptor
 * @argv:Program Name
 * Return : Excute A line void
 */
void _treat_file(char *line, int counter, FILE *fp, char **argv)
{
	char **cmd;
	int st = 0;

	cmd = _cmd_prase(line);

		if (_strncmp_(cmd[0], "exit", 4) == 0)
		{
			exit_file_bul(cmd, line, fp);
		}
		else if (_bultn_checker(cmd) == 0)
		{
			st = _builtin_handl(cmd, st);
			free(cmd);
		}
		else
		{
			st = _cmd_check(cmd, line, counter, argv);
			free(cmd);
		}
}
/**
 * exit_file_bul - Exit Shell Case Of File
 * @line: Line From A File
 * @cmd: Parsed Command
 * @fd:File Descriptor
 * Return : Case Of Exit in A File Line
 */
void exit_file_bul(char **cmd, char *line, FILE *fd)
{
	int statue, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha_(cmd[1][i++]) < 0)
		{
			perror("illegal number");
		}
	}
	statue = _atoi_(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(statue);



}
