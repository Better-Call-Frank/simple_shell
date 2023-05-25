#include "shell.h"

/**
 * _custom_puts - prints input string
 * @str: string to be printed
 *
 * Return: Nothing
 */
void _custom_puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_custom_putchar(str[i]);
		i++;
	}
}

/**
 * _custom_putchar - writes the character c to stderr
 * @c: character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _custom_putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd_custom - writes character c to given fd
 * @c: Character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int_putfd_custom(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd_custom - prints input string
 * @str: string to be printed
 * @fd: the file descriptor to write to
 *
 * Return: number of characters put
 */
int _putsfd_custom(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd_custom(*str++, fd);
	}
	return (i);
}
