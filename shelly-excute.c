#include "shell.h"

/**
 * execute_cmd - Execute a command
 * @cmd: Parsed command arguments
 * Return: Status code
 */
int execute_cmd(char **cmd)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        /* Child process */
        if (execve(cmd[0], cmd, environ) == -1)
        {
            perror("hsh");
        }
        exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        perror("hsh");
    }
    else
    {
        /* Parent process */
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return (1);
}
