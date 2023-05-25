#include <unistd.h>
#include "shell.h"
/**
 * change_dir - a function to change directory
 * @directory: directory name
 * @len: length
 * Return: 0 if success otherwise -1
 */

void change_dir(char *directory, int len)
{
	char cwd[len];

	if (getcwd(cwd, len) != NULL)
	{
		our_setenv("PWD", cwd, 1);
		if (directory != NULL)
			chdir(directory);
		else
			perror("getcwd() error");

	}

}
