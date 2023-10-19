#include "main.h"

/**
 * get_sigint - The crtl + c call in prompt handle
 * @sig: The handler signal
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
