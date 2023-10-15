#include "main.h"

/**
 * ___history_dis - Display History Of User Input Simple Shell
 * @c:Parsed Command
 * @s:Statue Of Last Excute
 * Return: 0 Succes -1 Fail
 */
int ___history_dis(__attribute__((unused))char **c, __attribute__((unused))int s)
{
	char *file = "history";
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int counter = 0;
	char *er;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		return (-1);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		counter++;
		er = _itoa_(counter);
		PRINTER(er);
		free(er);
		PRINTER(" ");
		PRINTER(line);

	}
	if (line)
		free(line);
	fclose(fp);
	return (0);
}
