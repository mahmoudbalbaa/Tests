#include "main.h"

/**
 * _checkdelim_ - Checks If A Character Match Any Char *
 * @c: Character To Check
 * @str: String To Check
 * Return: 1 Succes, 0 Failed
 */

unsigned int _checkdelim_(char c, const char *str)
{
	unsigned int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (c == str[i])
			return (1);
	}

	return (0);
}
