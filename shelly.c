#include "shelly.h"

int main(__attribute__((unused)) int argc, char **argv)
{
    char *input, **cmd;
    int counter = 0, status = 1;

    if (argv[1] != NULL)
        read_file(argv[1], argv);

    signal(SIGINT, signal_to_handel);

    while (status)
    {
        counter++;

        if (isatty(STDIN_FILENO))
            prompt();

        input = _getline();

        if (input[0] == '\0')
        {
            continue;
        }

        history(input);
        cmd = parse_cmd(input);

        if (_strcmp(cmd[0], "exit") == 0)
        {
            exit_bul(cmd, input, argv, counter);
        }
        else if (check_builtin(cmd) == 0)
        {
            status = handle_builtin(cmd, status);
        }
        else
        {
            status = check_cmd(cmd, input, counter, argv);
        }

        free_all(cmd, input);
    }

    return (status);
}
