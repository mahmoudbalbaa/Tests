#include "main.h"

/**
 * _putchar_ - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar_(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strncpy_ - copie a string
 * @dest:char
 *  @src:char
 * @n:int
 * Return:char
 */

char *_strncpy_(char *dest, char *src, int n)
{
int i;

i = 0;
	while (i < n && *(src + i))
	{
	*(dest + i) = *(src + i);
	i++;
	}
	while (i < n)
	{
	*(dest + i) = '\0';
	i++;
	}
	return (dest);
}

/**
 * _strlen_ - lenght of string
 * @s:char
 * Return:int
 */

int _strlen_(char *s)
{
	int i;

		for (i = 0; s[i] != '\0'; i++)
		{
			continue;
		}
return (i);
}

/**
 * _atoi_ - convert to a int
 * @s:string
 * Return:int
 */
int _atoi_(char *s)
{
int i, j, n, x;

	i = n = 0;
	x = 1;
	while ((s[i] < '0' || s[i] > '9') && (s[i] != '\0'))
	{
		if (s[i] == '-')
			x *= -1;
		i++;
	}
	j = i;
	while ((s[j] >= '0') && (s[j] <= '9'))
	{
		n = (n * 10) + x * ((s[j]) - '0');
		j++;
	}
	return (n);
}
/**
 * _puts_ - print a string
 * @str:pointer char
 * return:void
 */
void _puts_(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar_(str[i]);
	}
_putchar_('\n');
return;
}
