#include "shelly.h"

/**
 * echo_builtin - Execute the echo built-in command
 * @cmd: Parsed command
 * @st: Status of the last command executed
 * Return: Always 0
 */
int echo_builtin(char **cmd, __attribute__((unused)) int st)
{
	char *path;
	unsigned int pid = getppid();

	if (cmd[1] == NULL)
	{
		PRINTER("\n");
		return (0);
	}

	if (_strncmp(cmd[1], "$?", 2) == 0)
	{
		print_number_in(st);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$$", 2) == 0)
	{
		print_number(pid);
		PRINTER("\n");
	}
	else if (_strncmp(cmd[1], "$PATH", 5) == 0)
	{
		path = _getenv("PATH");
		PRINTER(path);
		PRINTER("\n");
		free(path);
	}
	else
		return (print_echo(cmd));

	return (0);
}
