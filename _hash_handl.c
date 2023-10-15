#include "main.h"

/**
 * _hash_handl - remove everything after #
 * @buff: input;
 * Return:void
 */

void _hash_handl(char *buff)
{
	int i;

	for (i = 0; buff[i] != '\0'; i++)
	{
		if (buff[i] == '#')
		{
			buff[i] = '\0';
			break;
		}
	}
}
