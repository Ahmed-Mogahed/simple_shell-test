#include "shelly.h"

/**
 * change_dir - Change the current working directory
 * @cmd: Parsed command
 * @er: Status of the last command executed
 * Return: 0 on success, -1 on failure
 */
int change_dir(char **cmd, __attribute__((unused)) int er)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (cmd[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(cmd[1], "-") == 0)
		value = chdir(getenv("OLDPWD"));
	else
		value = chdir(cmd[1]);

	if (value == -1)
	{
		perror("hsh");
		return (-1);
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
	return (0);
}
