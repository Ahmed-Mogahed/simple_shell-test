#include "shelly.h"

/**
 * print_number - Print Unsigned Int Using _putchar
 * @n: Unsigned Integer
 * Return: Void
 */
void print_number(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}

/**
 * print_number_in - Print Integer Using _putchar
 * @n: Integer
 * Return: void
 */
void print_number_in(int n)
{
	unsigned int x;

	if (n < 0)
	{
		_putchar('-');
		x = -n;
	}
	else
	{
		x = n;
	}

	if ((x / 10) > 0)
		print_number(x / 10);

	_putchar(x % 10 + '0');
}
