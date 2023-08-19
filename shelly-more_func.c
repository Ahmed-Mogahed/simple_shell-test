#include "shelly.h"

/**
 * array_len - Calculate the length of an array of strings
 * @arr: The array of strings
 * Return: The length of the array
 */
size_t array_len(char **arr)
{
    size_t len = 0;

    while (arr[len])
        len++;

    return len;
}

/**
 * _strcat - Concatenate two strings
 * @dest: The destination buffer
 * @src: The source string
 * Return: Pointer to the destination buffer
 */
char *_strcat(char *dest, const char *src)
{
    size_t dest_len = _strlen(dest);
    size_t i;

    for (i = 0; src[i] != '\0'; i++)
        dest[dest_len + i] = src[i];
    dest[dest_len + i] = '\0';

    return dest;
}
