#include "shell.h"

/**
 * _strcpy - a string that copies a string
 * @dest: destination
 * @src: source
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - a function that duplicates a string
 * @str: string to duplicate
 * Return: a pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *dub;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	dub = malloc(sizeof(char) * (len + 1));
	if (!dub)
		return (NULL);
	for (len++; len--;)
		dub[len] = *--str;
	return (dub);
}

/**
 * _puts - a function that prints an input string
 * @str: string to be printed
 * Return: void
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - a function that writes the character c to stdout
 * @c: character input
 * Return: On success 1 else -1
 */
int _putchar(char c)
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
}

