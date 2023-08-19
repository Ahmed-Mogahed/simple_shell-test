#include "shelly.h"

/**
 * display_history - Display History Of User Input Simple Shell
 * @cmd: Parsed Command
 * @status: Status Of Last Execute
 * Return: 0 Success, -1 Fail
 */
int display_history(__attribute__((unused)) char **cmd, __attribute__((unused)) int status)
{
    char *filename = ".simple_shell_history";
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    int counter = 0;
    char *counter_str;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return (-1);
    }
    while ((getline(&line, &len, fp)) != -1)
    {
        counter++;
        counter_str = _itoa(counter);
        PRINTER(counter_str);
        free(counter_str);
        PRINTER(" ");
        PRINTER(line);
    }
    if (line)
        free(line);
    fclose(fp);
    return (0);
}

/**
 * execute_echo - Execute Normal Echo
 * @cmd: Parsed Command
 * Return: 0 Success, -1 Fail
 */
int execute_echo(char **cmd)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        if (execve("/bin/echo", cmd, environ) == -1)
        {
            return (-1);
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        return (-1);
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return (1);
}
