#include "shell.h"

/**
 * _strdup - duplicates a string
 * @s: the given string
 *
 * Return: a pointer to the duplicate
 */
char *_strdup(char *s)
{
	int size, i;
	char *dest;

	if (!s)
		return (NULL);

	size = _strlen(s) + 1;
	dest = malloc(size * sizeof(char));
	if (!dest)
		return (NULL);

	for (i = 0; i < size; i++)
		*(dest + i) = *(s + i);

	*(dest + i) = '\0';

	return (dest);
}
