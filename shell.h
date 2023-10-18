#ifndef SHELL_HEADER_H
#define SHELL_HEADER_H

/* Standard Libraries */
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Prototypes */
void execute_command(char *line);
extern char **environ;
char *generate_full_path(char *directory, char *cmd);
char *get_command_path(char *line, char **argv);
void execute_program(char *cmd_path, char **argv);
char *check_path(char *cmd);
void execute_command(char *line);
ssize_t prompt(void);
void handle_eof(char *line);
char *_getline(void);

#endif /* SHELL_HEADER_H */

