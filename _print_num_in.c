#include "main.h"

/**
 * _print_num_in -Print Number Putchar
 * @n:Integer
 * Return: void
 */

void _print_num_in(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar_('-');
		x = -x;
	}
	if ((x / 10) > 0)
		_print_num(x / 10);

	_putchar_(x % 10 + '0');
}
