# Simple Shell Project

This project is a basic implementation of a Unix shell, also known as a command-line interpreter. The shell supports executing both built-in commands and external commands located in the system's PATH.

## Features

- Interactive mode: Users can enter commands one by one.
- Non-interactive mode: Commands can be read and executed from a file.
- Built-in commands: Supports built-in commands like `cd`, `env`, `help`, `echo`, and `history`.
- External commands: Can execute external commands from the system's PATH.
- History: Keeps track of previously executed commands.
- Signal handling: Handles Ctrl+C to interrupt and return to the prompt.

## Usage

To compile the shell program, use the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic *.c -o shelly
