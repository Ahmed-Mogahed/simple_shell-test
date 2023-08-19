#include "shelly.h"

/**
 * shelly_prompt - Display Shell Prompt
 */
void shelly_prompt(void)
{
	PRINTER("$ ");
}

/**
 * shelly_print_error - Display Error Based on Command and How Many Times Shell Looped
 * @input: User Input
 * @counter: Simple Shell Loop Count
 * @argv: Program Name
 * Return: Void
 */
void shelly_print_error(char *input, int counter, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(counter);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
