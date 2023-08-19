#include "shelly.h"

/**
 * shelly_parse_cmd - Parse Line Of Input
 * @input: User Input To Parse
 * Return: Array Of Char (Parsed) for Simple Shell
 */
char **shelly_parse_cmd(char *input)
{
    char **tokens;
    char *token;
    int i, buffsize = BUFSIZE;

    if (input == NULL)
        return (NULL);
    tokens = (char **)malloc(sizeof(char *) * buffsize);
    if (!tokens)
    {
        perror("hsh");
        return (NULL);
    }

    token = _strtok(input, DELIM);
    for (i = 0; token; i++)
    {
        tokens[i] = token;
        token = _strtok(NULL, DELIM);
    }
    tokens[i] = NULL;

    return (tokens);
}
