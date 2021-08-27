#include "holberton.h"

/**
 * _strcat - concatenate two strings
 * @dest: string to be appended to
 * @src: string to append
 * Return: concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int len = 0;
	int len2 = 0;
	int total_len = 0;
	int j = 0;

	/* find total length of both strings to _realloc */
	while (dest[len] != '\0')
	{
		len++;
		total_len++;
	}
	while (src[len2] != '\0')
	{
		len2++;
		total_len++;
	}

	/* _realloc because dest was malloced outside of function */
	dest = _realloc(dest, len, sizeof(char) * total_len + 1);

	while (src[j] != '\0')
	{
		dest[len] = src[j];
		len++;
		j++;
	}
	dest[len] = '\0';

	return (dest);
}
/**
 * _strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: int that tells num spaces in between, 0 if exactly the same string
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i])
		i++;

	if (s2[i])
		return (s1[i] - s2[i]);
	else
		return (0);
}

/**
 * _strcpy - copies the string pointed to by src,
 * including the terminating null byte (\0),
 * to the buffer pointed to by dest
 * @dest: copy source to this buffer
 * @src: this is the source to copy
 * Return: copy of original source
 */

char *_strcpy(char *dest, char *src)
{
	int i, len;

	for (len = 0; src[len] != '\0'; len++)
		;

	for (i = 0; i <= len; i++)
		dest[i] = src[i];

	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 * Return: pointer to duplicated string in allocated memory
 */
char *_strdup(char *str)
{
	char *duplicate_str;
	int i, len = 0;

	if (str == NULL) /* validate str input */
		return (NULL);

	while (str[len])
		len++;
	len++; /* add null terminator to length */

	duplicate_str = malloc(sizeof(char) * len); /* allocate memory */
	if (duplicate_str == NULL)
		return (NULL);

	i = 0;
	while (i < len)
	{
		duplicate_str[i] = str[i];
		i++;
	}

	return (duplicate_str);
}

/**
 * _strlen - find the length of a string
 * @s: pointer to the string
 * Return: characters in the string
 */
int _strlen(const char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
