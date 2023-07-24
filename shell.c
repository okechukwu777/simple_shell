#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - start of code
 * return: 0
 */

int main(void)
{
	char *command;

	while (1)
	{
	display_prompt();
	command = read_command();

	char *args[MAX_COMMAND_LENGTH];
	char *token = strtok(command, " ");
	int arg_index = 0;

	while (token != NULL)
	{
	args[arg_index] = token;
	arg_index++;
	token = strtok(NULL, " ");
	}
	args[arg_index] = NULL;

	execute_command(args[0], args);

	free(command);
	}
	return (0);
}

