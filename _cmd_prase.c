#include "main.h"

/**
 * _cmd_prase - Parse Line Of Input
 * @input:User Input To Parse
 * Return: Array Of Char (Parsed):Simple Shell
 */
char **_cmd_prase(char *input)
{
	char **tokens;
	char *token;
	int i, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok_(input, "\n ");
	for (i = 0; token; i++)
	{
		tokens[i] = token;
		token = _strtok_(NULL, "\n ");
	}
	tokens[i] = NULL;

	return (tokens);
}
