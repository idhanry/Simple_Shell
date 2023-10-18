#include "main.h"

/**
* bring_line - assigns the var line for idy_get
* @lineptr: The buffer that the input str store
* @buffer: The str that is called to line
* @n: The line size
* @j: The size of buffer
*/
void bring_line(char **lineptr, size_t *n, char *buffer, size_t j)
{

if (*lineptr == NULL)
{
	if  (j > BUFSIZE)
		*n = j;

	else
		*n = BUFSIZE;
	*lineptr = buffer;
}
else if (*n < j)
{
	if (j > BUFSIZE)
		*n = j;
	else
		*n = BUFSIZE;
	*lineptr = buffer;
}
else
{
	_strcpy(*lineptr, buffer);
	free(buffer);
}
}
/**
* idy_get - Read inpt from stream
* @lineptr: The input that the buffer stores
* @n: The size of lineptr
* @stream: The stream to read from
* Return: The bytes number
*/
ssize_t idy_get(char **lineptr, size_t *n, FILE *stream)
{
int i;
static ssize_t input;
ssize_t retval;
char *buffer;
char t = 'z';

if (input == 0)
	fflush(stream);
else
	return (-1);
input = 0;

buffer = malloc(sizeof(char) * BUFSIZE);
if (buffer == 0)
	return (-1);
while (t != '\n')
{
	i = read(STDIN_FILENO, &t, 1);
	if (i == -1 || (i == 0 && input == 0))
	{
		free(buffer);
		return (-1);
	}
	if (i == 0 && input != 0)
	{
		input++;
		break;
	}
	if (input >= BUFSIZE)
		buffer = _realloc(buffer, input, input + 1);
	buffer[input] = t;
	input++;
}
buffer[input] = '\0';
bring_line(lineptr, m, buffer, input);
retval = input;
if (i != 0)
	input = 0;
return (retval);
}
