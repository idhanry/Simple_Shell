#include "shell.h"

/**
 * process_command - execute corresponding actions and Process the command.
 * @argv: The strings array where argv[0] is the command.
 *
 * Return: 0 on success, 1 if the command was unsuccessful.
 */
int process_command(char **argv)
{
	int num_arg = num_args(argv);

	if (_strcmp(argv[0], "cd") == 0)
	{
		if (num_arg >= 1)
		{
			cd(argv[1]);
			return (0);
		}
	}
	if (_strcmp(argv[0], "env") == 0)
	{
		_env();
		return (0);
	}
	if (_strcmp(argv[0], "setenv") == 0)
	{
		if (num_arg == 3)
		{
			_setenv(argv[1], argv[2]);
			return (0);
		}
	}
	if (_strcmp(argv[0], "unsetenv") == 0)
	{
		if (num_arg == 2)
		{
			_unsetenv(argv[1]);
			return (0);
		}
	}
/*
 *	if ((argv, num_arg) alias_command)
 *	{
 *		return (0);
 *	}
 */
	return (1);
}

/**
 * _perrore - The exit error for string or negatives address
 * @err: The shell name
 * @count: The command number
 * @c: The command name
 * @arg: The command argument
 */

void _perrore(char *err, int count, char *c, char *arg)
{
	_print(err);
	_print(": ");
	_pnumber(count);
	_print(": ");
	_print(c);
	_print(": Illegal number: ");
	_print(arg);
	_print("\n");
}
