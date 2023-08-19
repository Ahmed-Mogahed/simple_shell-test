#include "shelly.h"

/**
 * exit_builtin - Execute the built-in "exit" command
 * @cmd: Parsed command
 * @counter: Simple Shell loop counter
 * @argv: Program name
 * Return: Void (Exits the shell)
 */
void exit_builtin(char **cmd, int counter, char **argv)
{
	int status = 0;
	char *er;

	if (cmd[1] != NULL)
	{
		status = _atoi(cmd[1]);
		if (status < 0)
		{
			er = _itoa(counter);
			PRINTER(argv[0]);
			PRINTER(": ");
			PRINTER(counter);
			PRINTER(": ");
			PRINTER(cmd[0]);
			PRINTER(": Illegal number: ");
			PRINTER(cmd[1]);
			PRINTER("\n");
			free(er);
			free(cmd);
			exit(2);
		}
	}

	free(cmd);
	exit(status);
}
