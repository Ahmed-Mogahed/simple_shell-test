#include "shelly.h"

/**
 * main - Simple Shell (Shelly)
 * @argc: Argument Count
 * @argv: Argument Value
 * Return: Exit Status
 */
int main(__attribute__((unused)) int argc, char **argv)
{
    char *input, **cmd;
    int counter = 0, status = 1;

    // Handle optional reading from a file (argv[1])
    if (argv[1] != NULL)
        read_file(argv[1], argv);

    signal(SIGINT, signal_to_handle);

    while (status)
    {
        counter++;
        
        // Display prompt if shell is interactive
        if (isatty(STDIN_FILENO))
            shelly_prompt();

        // Read user input
        input = shelly_getline();

        if (input[0] == '\0')
        {
            continue; // Ignore empty input
        }

        history(input);
        cmd = shelly_parse_cmd(input);

        // Check if input is the "exit" built-in command
        if (_strcmp(cmd[0], "exit") == 0)
        {
            exit_builtin(cmd, counter, argv);
        }
        // Check and handle other built-in commands
        else if (check_builtin(cmd) == 0)
        {
            handle_builtin(cmd, counter);
        }
        else
        {
            // Handle external commands
            check_cmd(cmd, input, counter, argv);
        }

        free_all(cmd, input);
    }

    return (0);
}
