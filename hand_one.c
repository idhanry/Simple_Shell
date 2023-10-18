#include "main.h"

/**
 * * hand_one - one information for the builtin one.
 * * Return: no return
 */
void hand_one(void)
{
	char *one = "one: one [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, one, _strlen(one));
	one = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, one, _strlen(one));
	one = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, one, _strlen(one));
}
/**
 * * hand_one_alias - one information for the alias builtin.
 * * Return: no return
 */
void hand_one_alias(void)
{
	char *one = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, one, _strlen(one));
	one = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, one, _strlen(one));
}
/**
 * * hand_one_cd - one information for the alias builtin.
 * * Return: no return
 */
void hand_one_cd(void)
{
	char *one = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, one, _strlen(one));
	one = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, one, _strlen(one));
}
