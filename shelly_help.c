#include "shelly.h"

/**
 * display_help - Display help for built-in commands
 * @cmd: Parsed command
 * @er: Exit status of the previous command
 * Return: 0 (Success)
 */
int display_help(char **cmd, __attribute__((unused)) int er)
{
	if (cmd[1] == NULL)
	{
		PRINTER("Shell Help:\n");
		PRINTER("Usage: command [options]\n");
		PRINTER("List of built-in commands:\n");
		PRINTER("cd [directory]: Change current directory\n");
		PRINTER("env: Display environment variables\n");
		PRINTER("help: Display this help message\n");
		PRINTER("exit [status]: Exit the shell\n");
		PRINTER("echo [text]: Display text\n");
		PRINTER("history: Display command history\n");
	}
	else
	{
		PRINTER("No help available for this command\n");
	}
	return (0);
}
