#include "shell.h"


/**
* The handle_segfault - the segmentation fault handle
* @signo: The number signal
*/
void handle_segfault(int signo __attribute__((unused)))
{
	/* Save the program's state and exit gracefully.*/
	exit(1);
}
