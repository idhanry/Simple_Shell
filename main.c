#include "shell.h"

/**
 * prompt - The shell prompt prints
 * Return: The number of written bytes, or -1 on failure.
 */
ssize_t prompt(void)
{
	return (write(STDOUT_FILENO, "#cisfun$ ", 9));
}

/**
 * handle_eof - The EOF (Ctrl+D) scenario.
 * @line: The buffer line input.
 */
void handle_eof(char *line)
{
	ssize_t bytes_written;

	bytes_written = write(STDOUT_FILENO, "\n", 1);
	if (bytes_written == -1)
	{
		perror("Error writing to standard output");
		free(line);
		exit(EXIT_FAILURE);
	}
	free(line);
	exit(EXIT_SUCCESS);
}

/**
 * main - The simple shell point of entry.
 * @argc: The number of Argument count.
 * @argv: The arguments of array.
 * Return: Always 0 (success).
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	(void) argc;
	(void) argv;

	while (1)
	{
		if (prompt() == -1)
		{
			perror("Error writing to standard output");
			exit(EXIT_FAILURE);
		}

		read = getline(&line, &len, stdin);

		/* Check for End of File (EOF) or Ctrl+D */
		if (read == -1)
			handle_eof(line);

		/* Command (line length greater than 1), execute it */
		if (strlen(line) > 1)
		{
			line[read - 1] = '\0';  /* remove newline character */
			execute_command(line);
		}
	}
	free(line);
	return (0);
}
