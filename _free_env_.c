#include "main.h"

/**
 * _free_env_ - Free Enviroment Variable Array
 * @env:  Environment variables.
 * Return: Void
 */

void _free_env_(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
		free(env[i]);
}
