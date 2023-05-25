#include "shell.h"

/**
 * is_cmd - a function that determines if a file is an executable command
 * @info: info struct
 * @path: PATH
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
		return (1);
	return (0);
}
/**
 * dup_chars - a function to  duplicate characters
 * @pathstr: PATH
 * @start: starting index
 * @stop: stopping index
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	int size = 1024;
	static char buffer[size];
	int i = 0, j = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buffer[j++] = pathstr[i];
	buffer[j] = 0;
	return (buffer);
}

/**
 * find_path - a function that finds this cmd in the PATH string
 * @info: info struct
 * @pathstr: PATH string
 * @cmd: cmd to find
 * Return: path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, c_pos = 0;
	char *mypath;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			mypath = dup_chars(pathstr, c_pos, i);
			if (!*path)
				_strcat(mypath, cmd);
			else
			{
				_strcat(mypath, "/");
				_strcat(mypath, cmd);
			}
			if (is_cmd(info, mypath))
				return (mypath);
			if (!pathstr[i])
				break;
			c_pos = i;
		}
		i++;
	}
	return (NULL);
}

