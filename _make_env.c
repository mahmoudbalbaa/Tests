#include "main.h"

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
