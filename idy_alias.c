#include "shell.h"

/**
 * init_aliases - The aliases with some standard values initializes
 * @aliases: The linked list of aliases head
 */
void init_aliases(alias_t **aliases)
{
	set_alias(aliases, "l", "ls -CF");
	set_alias(aliases, "la", "ls -A");
	set_alias(aliases, "ll", "ls -alF");
	set_alias(aliases, "ls", "ls --color=auto");
}

/**
 * alias_command - The command alias
 * @argv: argument
 * @num_arg: The arguments number
 *
 * Return: 0 if successful
 */
int alias_command(char *argv[MAX_ARGS], int num_arg __attribute__((unused)))
{
	static alias_t *aliases;
	static int initialized;
	int i;
	char *name, *value;
	alias_t *alias;

	if (!initialized)
	{
		init_aliases(&aliases);
		initialized = 1;
	}

	if (_strcmp(argv[0], "alias") != 0)
		return (0);

	if (num_arg == 1)
	{
		for (alias = aliases; alias; alias = alias->next)
			print_alias(alias);
		return (1);
	}
	for (i = 1; i < num_arg; i++)
	{
		name = argv[i];
		value = _strchr(argv[i], '=');
		if (value)
		{
			*value = '\0';/*replaces '=' by '\0'*/
			value++;
			if (*value == '\0')
				continue;
			set_alias(&aliases, name, value);
		}
		else
		{
			print_all_aliases(aliases);
		}
	}
	return (1);
}


/**
 * set_alias - The sets an alias
 * @aliases: The head of the aliases linked list
 * @name: The alias name
 * @value: The alias value
 */
void set_alias(alias_t **aliases, char *name, char *value)
{
	alias_t *alias;

	for (alias = *aliases; alias; alias = alias->next)
		if (_strcmp(alias->name, name) == 0)
			break;

	if (alias)
	{
		free(alias->value);
		alias->value = _strdup(value);
	}
	else
	{
		alias = malloc(sizeof(*alias));
		if (!alias)
			return;
		alias->name = _strdup(name);
		alias->value = _strdup(value);
		alias->next = *aliases;
		*aliases = alias;
	}
	free(alias);
}

/**
 * print_alias - The alias prints
 * @alias: The print alias
 */
void print_alias(alias_t *alias)
{
	if (alias->value[0] != '\'')
	{
		write(1, "alias ", 6);
		write(1, alias->name, _strlen(alias->name));
		write(1, "='", 2);
		write(1, alias->value, _strlen(alias->value));
		write(1, "'\n", 2);
	}
	else
	{
		write(1, "alias ", 6);
		write(1, alias->name, _strlen(alias->name));
		write(1, "=", 1);
		write(1, alias->value, _strlen(alias->value));
		write(1, "\n", 1);
	}
}
