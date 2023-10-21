#include "shell.h"

/**
* Trailing_and_leading_spaces_remove - The trailing spaces from a string remove
* @str: The string to remove trailing spaces from
*/
void remove_trailing_and_leading_spaces(char *str)
{
	size_t len = _strlen(str);
	size_t start = 0;
	size_t i;

	/* Remove trailing spaces */
	if (len > 0)
	{
		while (len > 0 && str[len - 1] == ' ')
			len--;
		str[len] = '\0';
	}

	/* Find the starting position after removing trailing spaces */
	while (str[start] == ' ')
		start++;

	/* Shift the string to remove leading spaces */
	if (start > 0)
	{
		i = 0;
		while (str[start + i] != '\0')
		{
			str[i] = str[start + i];
			i++;
		}
		str[i] = '\0';
	}
}

/**
* tokenize - The string into an array of tokens tokenize
* @command: The string tokenize
* @argv: The array tokens store
*/

void tokenize(char *command, char *argv[MAX_ARGS])
{
	char *token;
	int i = 0;

	token = _strtok(command, " ");
	while (token != NULL)
	{
		argv[i++] = token;
		token = _strtok(NULL, " ");
	}
	argv[i] = NULL;
}

/**
* num_args - The number of arguments in an array count
* @argv: array of arguments
*
* Return: The number of argv arguments
*/
int num_args(char *argv[])
{
	int i = 0;

	while (argv[i] != NULL)
		i++;
	return (i);
}

/**
* _atoi - The string to an integer convert
* @str: The string to convert
*
* Return: The value integer str
*/
int _atoi(const char *str)
{
	int i, n = 0;
	int sign = 1;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
			sign = -1;
		else if (str[i] >= '0' && str[i] <= '9')
			n = n * 10 + (str[i] - '0');
		else
			break;
	}

	return (n * sign);
}

/**
* _1exit - The exit with a status code
* @status: The status code to exit with
* @c: The count of command
* @a: The name of shell
* @ag: The string of command input
* Return: exit code
*/
int _1exit(char *status __attribute__((unused)), int c, char *a, char **ag)
{
	int i = ex_code;
	int j;

	if (status != NULL)
	{
		j = 0;
		while (status[j])
		{
			if (!(status[j] > 47  && status[j] < 58))
			{
				_perrore(a, c, ag[0], ag[1]);
				ex_code = 2;
				return (500);
			}
			j++;
		}
		i  = _atoi(status);
	}
	return (i);
}
