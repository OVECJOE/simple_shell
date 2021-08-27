#include "shell.h"

/**
 * _strlen - finds the length of a string
 * @s: the given string
 *
 * Return: the length
 */
int _strlen(const char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;

	return (i);
}

/**
 * _strstr - Implementation of the strstr function
 * @haystack: Just as the name suggests
 * @needle: the string to be searched for
 *
 * Return: a pointer to the first character of @needle
 * in @haystack if found, else NULL
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)
	{
		if ((*haystack == *needle) && cmp(haystack, needle))
			return (haystack);
		haystack++;
	}

	return (NULL);
}

/**
 * _strcpy - copies the content of a string to another
 * @dest: the destination string
 * @src: the source of the contents to be copied
 *
 * Return: @dest
 */
char *_strcpy(char *dest, const char *src)
{
	char *temp = dest;

	while (*src)
		*temp++ = *src++;

	*temp = '\0';

	return (dest);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination string
 * @src: the source string
 *
 * Return: the result of concatenation
 */
char *_strcat(char *dest, const char *src)
{
	int len_dest, i = 0;

	len_dest = _strlen(dest);

	while (src[i])
		dest[len_dest++] = src[i++];
	dest[len_dest] = '\0';

	return (dest);
}

/**
 * _strcmp - Compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if equal, -ve if @s1 < @s2, else +ve
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i]; i++)
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

	return (0);
}


