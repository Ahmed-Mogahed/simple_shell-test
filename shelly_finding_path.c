#include "shelly.h"

/**
 * find_path - Find the path to an executable command
 * @cmd: Command to find the path for
 * Return: Full path to the command, or NULL if not found
 */
char *find_path(char *cmd)
{
	char *path, *token, *full_path;
	struct stat st;

	if (cmd == NULL)
		return (NULL);

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	token = _strtok(path, ":");
	while (token)
	{
		full_path = build(token, cmd);
		if (stat(full_path, &st) == 0)
		{
			free(path);
			return (full_path);
		}
		free(full_path);
		token = _strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
