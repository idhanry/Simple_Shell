#include "main.h"

/**
 * read_line - The input string reads.
 *
 * @i_eof: The getline function value return
 * Return: input string
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
