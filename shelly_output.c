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
 * Return: Void
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

/**
 * print_echo - Print Arguments
 * @cmd: Array of Arguments
 * Return: 1 Always (Success)
 */
int print_echo(char **cmd)
{
	unsigned int i, j;

	for (i = 1; cmd[i]; i++)
	{
		for (j = 0; cmd[i][j]; j++)
		{
			_putchar(cmd[i][j]);
		}
		if (cmd[i + 1])
			_putchar(' ');
	}
	_putchar('\n');
	return (1);
}
