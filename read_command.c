#include "shell.h"
#include <stdlib.h>
#include <stdio.h>

char *read_command() 
{
	char *command = malloc(MAX_COMMAND_LENGTH * sizeof(char));
	if (command == NULL) 
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL) 
	{
		if (feof(stdin)) 
		{
			printf("\n");
			exit(0);
		} 
		else 
		{
			perror("fgets");
			exit(EXIT_FAILURE);
		}
	}
	remove_newline(command);
	return command;
}

