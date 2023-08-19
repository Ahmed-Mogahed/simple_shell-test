#include "shelly.h"

/**
 * is_whitespace - Check if a character is a whitespace character
 * @c: The character to check
 * Return: 1 if c is whitespace, 0 otherwise
 */
int is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v');
}

/**
 * is_digit - Check if a character is a digit
 * @c: The character to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}
