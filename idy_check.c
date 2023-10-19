#include "shell.h"

/**
 * access_check - The file access checks
 * @arg: The arg command
 * @cmd: The arg command
 * @err: The string error
 * @c: The command count
 * @e: The variable environment
 *
 * Return: 0 if success, 1 otherwise
 */

int access_check(char **arg, char *cmd, char *err, int c, char **e)
{
	pid_t idcheck;
	char *p = NULL;

	p = (cmd == NULL) ? arg[0] : cmd;
	if (access(p, X_OK) == 0)
	{
		idcheck = fork();
		if (idcheck == 0)
		{
			_execve(p, arg, e);
		}
		return (0);
	}
	else
	{
		_perror(err, c, p);
		return (1);
	}
}

/**
 * _putchar - The character c to stdout writes
 * @c: The print character
 * Return: 1 on success
 */

int _putchar(char c)
{
	return (write(2, &c, 1));
}
