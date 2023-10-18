#include "main.h":

/**
 * * cmp_env_name - Compares environment variable names with the passed name.
 * *
 * * @nenv: The name of the environment variable
 * * @name: The name to compare with
 * *
 * * Return: 0 if names are not equal, otherwise,
 * a value indicating the position.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{

			return (0);
		}
	}

	return (i + 1);
}

/**
 * * _getenv - Gets an environment variable by name.
 * *
 * * @name: The name of the environment variable to retrieve
 * * @_environ: The environment variables array
 * *
 * * Return: The value of the environment variable if found, NULL otherwise.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env = NULL;
	int i, mov;

	for (i = 0; _environ[i]; i++)
	{
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * * _env - Prints the environment variables.
 * *
 * * @datash: Relevant data structure
 * * @return: 1 on success, 0 on failure
 */
int _env(data_shell *datash)
{
	int i, k;

	for (i = 0; datash->_environ[i]; i++)
	{
		for (k = 0; datash->_environ[i][k]; k++)
			;
		write(STDOUT_FILENO, datash->_environ[i], k);
		write(STDOUT_FILENO, "\n", 1);
	}

	datash->status = 0;
	return (1);
}

