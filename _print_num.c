#include "main.h"

/**
 * _print_num -Print Unsigned Int Putchar
 * @n: Unisigned Integer
 * Return: Void
 */

void _print_num(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		_print_num(x / 10);

	_putchar_(x % 10 + '0');
}
