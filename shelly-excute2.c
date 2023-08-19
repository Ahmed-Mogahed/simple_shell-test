#include "shelly.h"

/**
 * execute_file - Execute commands from a file
 * @filename: Name of the file containing commands
 * Return: Void
 */
void execute_file(char *filename)
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("hsh");
        return;
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line[read - 1] = '\0';
        char **cmd = shelly_parse_cmd(line);
        if (cmd)
        {
            if (_strcmp(cmd[0], "exit") == 0)
            {
                free_all(cmd, line);
                break;
            }
            execute_cmd(cmd);
            free_all(cmd, line);
        }
    }

    fclose(file);
    if (line)
        free(line);
}
